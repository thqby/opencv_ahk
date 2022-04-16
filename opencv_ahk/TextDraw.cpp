#include "pch.h"
#include "TextDraw.h"
#include "util.h"
#ifdef _T
#undef _T
#endif
#include <tchar.h>

void TextDraw::getTextSize(LPTSTR str, int& w, int& h, int& rowh)
{
	SIZE size;
	LPTSTR p = str, ln;
	LONG strBaseW = 0, strBaseH = 0, nnh = 0;
	while (ln = _tcschr(p, '\n')) {
		GetTextExtentPoint(mDC, p, (int)(ln - p), &size);
		strBaseW = std::max(strBaseW, size.cx);
		strBaseH = std::max(strBaseH, size.cy);
		nnh++;
		p = ln + 1;
	}
	GetTextExtentPoint(mDC, p, (int)_tcslen(p), &size);
	strBaseW = std::max(strBaseW, size.cx);
	strBaseH = std::max(strBaseH, size.cy);
	nnh++;
	rowh = strBaseH;
	h = strBaseH * nnh;
	w = strBaseW;
}

void TextDraw::putText(cv::InputOutputArray img, LPTSTR text, cv::Point org, cv::Scalar color, bool bottomLeftOrigin)
{
	cv::Mat dst = img.getMat();
	if ((dst.type() & 7) != CV_8U || dst.channels() == 2 || dst.channels() > 4)
		return;
	int strw, strh, rowh, left, top, right, bottom;
	getTextSize(text, strw, strh, rowh);
	if (bottomLeftOrigin)
		org.y -= strh;
	if (org.x > dst.cols || org.y > dst.rows)
		return;
	left = org.x < 0 ? -org.x : 0;
	top = org.y < 0 ? -org.y : 0;
	if (org.x + strw < 0 || org.y + strh < 0)
		return;
	right = org.x + strw > dst.cols ? dst.cols - org.x - 1 : strw - 1;
	bottom = org.y + strh > dst.rows ? dst.rows - org.y - 1 : strh - 1;
	org.x = org.x < 0 ? 0 : org.x;
	org.y = org.y < 0 ? 0 : org.y;

	BITMAPINFO bmp = { 0 };
	BITMAPINFOHEADER& bih = bmp.bmiHeader;
	int strDrawLineStep = strw * 3 % 4 == 0 ? strw * 3 : (strw * 3 + 4 - ((strw * 3) % 4));

	bih.biSize = sizeof(BITMAPINFOHEADER);
	bih.biWidth = strw;
	bih.biHeight = strh;
	bih.biPlanes = 1;
	bih.biBitCount = 24;
	bih.biCompression = BI_RGB;
	bih.biSizeImage = bih.biHeight * strDrawLineStep;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;

	void* pDibData = 0;
	HBITMAP hBmp = CreateDIBSection(mDC, &bmp, DIB_RGB_COLORS, &pDibData, 0, 0);
	HBITMAP hOldBmp = (HBITMAP)SelectObject(mDC, hBmp);

	int outTextY = 0;
	LPTSTR p = text, ln;
	while (ln = _tcschr(p, '\n'))
	{
		TextOut(mDC, 0, outTextY, p, (int)(ln - p));
		outTextY += rowh;
		p = ln + 1;
	}
	TextOut(mDC, 0, outTextY, p, (int)_tcslen(p));

	size_t dstStep = dst.elemSize();
	int channels = std::min(3, dst.channels());
	uchar* src = (uchar*)pDibData + (size_t)left * 3 + (size_t)(strh - top - 1) * strDrawLineStep;
	uchar cl[3] = { (uchar)color.val[0],(uchar)color.val[1],(uchar)color.val[2] };

	for (int y = top; y <= bottom; ++y, src -= strDrawLineStep) {
		auto _src = src;
		auto _dst = dst.ptr(org.y + y - top, org.x);
		for (int x = left; x <= right; ++x, _src += 3, _dst += dstStep)
			for (int i = 0; i < channels; ++i)
				if (_src[i]) {
					double v = _src[i] / 255.0;
					uchar c = uchar(v * cl[i] + (1 - v) * _dst[i]);
					_dst[i] = c;
				}
	}
	SelectObject(mDC, hOldBmp);
	DeleteObject(hBmp);
}

void TextDraw::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount)
{
	ResultType __result;
	switch (aID)
	{
	case M___Delete: {
		HFONT ft = (HFONT)SelectObject(mDC, mOldFont);
		DeleteObject(ft);
		DeleteDC(mDC);
		return;
	}
	case M___New: {
		LOGFONT lf{};
		int fontSize = 24, weight = 0;
		BYTE italic = 0, underline = 0;
		LPTSTR font = _T("");
		if (aParamCount)
			font = g_ahkapi->TokenToString(*aParam[0]);
		if (aParamCount > 1 && ParamIndexToVal(1, fontSize, 2))
			_o_return_result;
		if (aParamCount > 2 && ParamIndexToVal(2, weight, 2))
			_o_return_result;
		if (aParamCount > 3 && ParamIndexToVal(3, italic, 2))
			_o_return_result;
		if (aParamCount > 4 && ParamIndexToVal(4, underline, 2))
			_o_return_result;
		lf.lfHeight = -fontSize;
		lf.lfWidth = 0;
		lf.lfEscapement = 0;
		lf.lfOrientation = 0;
		lf.lfWeight = weight;
		lf.lfItalic = italic;
		lf.lfUnderline = underline;
		lf.lfStrikeOut = 0;
		lf.lfCharSet = DEFAULT_CHARSET;
		lf.lfOutPrecision = 0;
		lf.lfClipPrecision = 0;
		lf.lfQuality = PROOF_QUALITY;
		lf.lfPitchAndFamily = 0;
		memcpy(lf.lfFaceName, font, std::min(_tcslen(font) * sizeof(TCHAR), sizeof(lf.lfFaceName)));
		HFONT ft = CreateFontIndirect(&lf);
		mDC = CreateCompatibleDC(0);
		mOldFont = (HFONT)SelectObject(mDC, ft);
		SetTextColor(mDC, RGB(255, 255, 255));
		SetBkColor(mDC, 0);
		return;
	}
	case M_putText: {
		cv::_InputOutputArray img;
		LPTSTR text;
		cv::Point org;
		cv::Scalar color;
		bool bottomLeftOrigin = false;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		text = g_ahkapi->TokenToString(*aParam[1]);
		if (ParamIndexToVal(2, org))
			_o_return_result;
		if (ParamIndexToVal(3, color))
			_o_return_result;
		if (aParamCount > 4 && ParamIndexToVal(4, (char&)bottomLeftOrigin, 2))
			_o_return_result;
		putText(img, text, org, color, bottomLeftOrigin);
		return;
	}
	case M_getTextSize: {
		LPTSTR text = g_ahkapi->TokenToString(*aParam[0]);
		cv::Size size;
		int rowh;
		getTextSize(text, size.width, size.height, rowh);
		return ValToResult(size, aResultToken);
	}
	default:
		break;
	}
}

thread_local IAhkApi::Prototype* TextDraw::sPrototype = nullptr;

ObjectMember TextDraw::sMember[] = {
	Object_Method(__New, 0, NA),
	Object_Method(__Delete, 0, 0),
	Object_Method(putText, 4, 5),
	Object_Method(getTextSize, 1, 1),
};

int TextDraw::sMemberCount = _countof(sMember);