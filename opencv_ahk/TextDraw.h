#pragma once
#include <ahkapi.h>
#include <opencv2/opencv.hpp>


class TextDraw : public Object
{
	HDC mDC;
	HFONT mOldFont;

	enum MemBerID {
		M___New,
		M___Delete,
		M_getTextSize,
		M_putText,
	};

public:
	void getTextSize(LPTSTR str, int& w, int& h, int& rowh);
	void putText(cv::InputOutputArray img, LPTSTR text, cv::Point org, cv::Scalar color, bool bottomLeftOrigin = false);
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

