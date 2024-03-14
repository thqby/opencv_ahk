#include "pch.h"
#include "util.h"
#include "cv_mat.h"
#include "cv_class.h"
#include "Vector.h"


int MatchParamTypes(ExprTokenType* aParam[], int aParamCount, char* def) {
	static const char typeindex[] = { 's','i','f','?','v','o' };
	ExprTokenType tmp, *p;
	int i;
	char c, t, d = 0;
	for (i = 0; c = *def++; i++) {
		if (i < aParamCount) {
			if (aParam[i]->symbol == SYM_VAR)
				g_ahkapi->VarToToken(aParam[i]->var, tmp), p = &tmp;
			else p = aParam[i];
			if ((t = typeindex[p->symbol]) == c || (t == 'o' && (c == 'v' && dynamic_cast<VarRef*>(p->object)) || (c == 'a' && dynamic_cast<Array*>(p->object)))) {
				if (*def == '?') d++, def++;
			}
			else if (t == '?' && *def == '?') {
				d++, def++;
			}
			else return i << 8 | c;
		}
		else if (d || *def == '?')
			return 0;
		else return 0xffffff << 8 | c;
	}
	if (i == aParamCount)
		return 0;
	return 0xffffff00;
}

ResultType ObjectGetPtrSize(Object* obj, void*& ptr, size_t* psize, bool) {
	ResultToken token{};
	ResultType result = CONDITION_TRUE;
	ptr = nullptr;
	token.SetValue(_T("")), token.result = OK;
	if (g_ahkapi->Object_GetProp(token, obj, _T("Ptr"), false, nullptr, 0) && token.symbol == SYM_INTEGER) {
		ptr = (void*)token.value_int64;
		if (psize) {
			if (g_ahkapi->Object_GetProp(token, obj, _T("Size"), false, nullptr, 0) && token.symbol == SYM_INTEGER)
				*psize = (size_t)token.value_int64;
			else {
				*psize = 0;
				result = g_ahkapi->TypeError(_T("Buffer"), token);
			}
		}
	}
	else
		result = g_ahkapi->TypeError(_T("Buffer"), token);
	g_ahkapi->ResultTokenFree(token);
	return result;
}

ExprTokenType VarRefToToken(VarRef* var) {
	ExprTokenType val;
	g_ahkapi->VarToToken(var, val);
	return val;
}

__int64 TokenToInt64(ExprTokenType& token) {
	__int64 val = 0;
	TokenToVal(token, val, true);
	return val;
}
double TokenToDouble(ExprTokenType& token) {
	double val = 0.0;
	TokenToVal(token, val, true);
	return val;
}
IObject* TokenToObject(ExprTokenType& token) {
	IObject* val = nullptr;
	TokenToObject(token, val, nullptr);
	return val;
}
VarRef* TokenToVarRef(ExprTokenType& token) {
	VarRef* val = nullptr;
	TokenToVal(token, val, true);
	return val;
}


ResultType TokenToVal(ExprTokenType& token, __int64& val, char ignore) {
	ExprTokenType vt;
	if (g_ahkapi->TokenToNumber(token, vt))
		val = vt.symbol == SYM_INTEGER ? vt.value_int64 : (__int64)vt.value_double;
	else if (ignore == 1 || ignore == 2 && token.symbol == SYM_MISSING) {}
	else
		return g_ahkapi->TypeError(_T("Integer"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, char& val, char ignore) {
	ExprTokenType vt;
	if (g_ahkapi->TokenToNumber(token, vt))
		val = (char)(vt.symbol == SYM_INTEGER ? vt.value_int64 : (__int64)vt.value_double);
	else if (ignore == 1 || ignore == 2 && token.symbol == SYM_MISSING) {}
	else
		return g_ahkapi->TypeError(_T("Integer"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, uchar& val, char ignore) { return TokenToVal(token, (char&)val, ignore); }

ResultType TokenToVal(ExprTokenType& token, int& val, char ignore) {
	ExprTokenType vt;
	if (g_ahkapi->TokenToNumber(token, vt))
		val = (int)(vt.symbol == SYM_INTEGER ? vt.value_int64 : (__int64)vt.value_double);
	else if (ignore == 1 || ignore == 2 && token.symbol == SYM_MISSING) {}
	else
		return g_ahkapi->TypeError(_T("Integer"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, float& val, char ignore) {
	ExprTokenType vt;
	if (g_ahkapi->TokenToNumber(token, vt))
		val = vt.symbol == SYM_INTEGER ? (float)vt.value_int64 : (float)vt.value_double;
	else if (ignore == 1 || ignore == 2 && token.symbol == SYM_MISSING) {}
	else
		return g_ahkapi->TypeError(_T("Float"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, double& val, char ignore) {
	ExprTokenType vt;
	if (g_ahkapi->TokenToNumber(token, vt))
		val = vt.symbol == SYM_INTEGER ? (double)vt.value_int64 : vt.value_double;
	else if (ignore == 1 || ignore == 2 && token.symbol == SYM_MISSING) {}
	else
		return g_ahkapi->TypeError(_T("Float"), token);
	return CONDITION_TRUE;
}

ResultType TokenToObject(ExprTokenType& token, IObject*& val, LPTSTR type) {
	ExprTokenType vt;
	if (token.symbol == SYM_VAR)
		g_ahkapi->VarToToken(token.var, vt);
	else vt = token;
	if (vt.symbol == SYM_OBJECT)
		val = vt.object;
	else if (!type)
		val = nullptr;
	else return g_ahkapi->TypeError(type, token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, VarRef*& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	val = dynamic_cast<VarRef*>(obj);
	if (!val && !ignore)
		return g_ahkapi->TypeError(_T("VarRef"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::String& str, char ignore) {
	TCHAR buf[256];
	size_t len;
	if (token.symbol == SYM_MISSING)
		return CONDITION_TRUE;
	auto s = g_ahkapi->TokenToString(token, buf, &len);
#ifdef _UNICODE
	auto l = WideCharToMultiByte(CP_ACP, 0, s, (int)len, 0, 0, 0, 0);
	str.resize(l);
	WideCharToMultiByte(CP_ACP, 0, s, (int)len, (char*)str.data(), l, 0, 0);
#else
	str = s;
#endif // _UNICODE
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::Mat& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(Mat::sPrototype))
		val = ((Mat*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("Mat"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::UMat& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(UMat::sPrototype))
		val = ((UMat*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("UMat"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::_InputArray& val, char ignore) {
	Object* obj = dynamic_cast<Object*>(TokenToObject(token));
	if (obj) {
		if (obj->mBase == Mat::sPrototype)
			val = ((Mat*)obj)->mC;
		else if (obj->mBase == UMat::sPrototype)
			val = ((UMat*)obj)->mC;
		else if (obj->mBase == cuda_GpuMat::sPrototype)
			val = ((cuda_GpuMat*)obj)->mC;
		else if (obj->IsOfType(VectorBase::sPrototype)) {
			int flags = ((VectorBase*)obj)->mFlags;
			void* vec = ((VectorBase*)obj)->mPtr;
			val = cv::_InputArray(flags, vec);
		}
		else obj = nullptr;
	}
	if (!obj && !ignore)
		return g_ahkapi->TypeError(_T("Mat or UMat or GpuMat or Vector"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::_OutputArray& val, char ignore) {
	Object* obj = dynamic_cast<Object*>(TokenToObject(token));
	if (obj) {
		if (obj->mBase == Mat::sPrototype)
			val = ((Mat*)obj)->mC;
		else if (obj->mBase == UMat::sPrototype)
			val = ((UMat*)obj)->mC;
		else if (obj->mBase == cuda_GpuMat::sPrototype)
			val = ((cuda_GpuMat*)obj)->mC;
		else if (obj->IsOfType(VectorBase::sPrototype)) {
			int flags = ((VectorBase*)obj)->mFlags & ~cv::ACCESS_READ;
			void* vec = ((VectorBase*)obj)->mPtr;
			val = cv::_OutputArray(flags, vec);
		}
		else obj = nullptr;
	}
	if (!obj && !ignore)
		return g_ahkapi->TypeError(_T("Mat or UMat or GpuMat or Vector"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::_InputOutputArray& val, char ignore) {
	Object* obj = dynamic_cast<Object*>(TokenToObject(token));
	if (obj) {
		if (obj->mBase == Mat::sPrototype)
			val = ((Mat*)obj)->mC;
		else if (obj->mBase == UMat::sPrototype)
			val = ((UMat*)obj)->mC;
		else if (obj->mBase == cuda_GpuMat::sPrototype)
			val = ((cuda_GpuMat*)obj)->mC;
		else if (obj->IsOfType(VectorBase::sPrototype)) {
			int flags = ((VectorBase*)obj)->mFlags & ~cv::ACCESS_READ;
			void* vec = ((VectorBase*)obj)->mPtr;
			val = cv::_InputOutputArray(flags, vec);
		}
		else obj = nullptr;
	}
	if (!obj && !ignore)
		return g_ahkapi->TypeError(_T("Mat or UMat or GpuMat or Vector"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::KeyPoint& val, char ignore) {
	cv::KeyPoint* kp = nullptr;
	auto result = TokenToVal(token, kp, ignore);
	if (kp)val = *kp;
	return result;
}

ResultType TokenToVal(ExprTokenType& token, cv::UsacParams& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(UsacParams::sPrototype))
		val = ((UsacParams*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("UsacParams"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::DMatch& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(DMatch::sPrototype))
		val = *((DMatch*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("DMatch"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::Range& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "ii", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Size& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "ii", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Size2f& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "ff", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Vec2b& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec2d& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec2f& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec2i& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec2s& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec2w& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec3b& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec3d& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec3f& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec3i& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec3s& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec3w& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec4b& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec4d& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec4f& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec4i& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec4s& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec4w& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec6d& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec6f& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec6i& val, char ignore) { return TokenToVec(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, cv::Vec8i& val, char ignore) { return TokenToVec(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, cv::Scalar& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "dddd", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Rect& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "iiii", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Rect2d& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "dddd", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Point& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "ii", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Point2f& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "ff", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::Point2d& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "dd", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::RotatedRect& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "fffff", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::TermCriteria& val, char ignore) {
	Array* arr = dynamic_cast<Array*>(TokenToObject(token));
	if (arr)return ArrayToBin(arr, (char*)&val, "iid", ignore);
	else return ignore ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
}

ResultType TokenToVal(ExprTokenType& token, cv::CirclesGridFinderParameters& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(CirclesGridFinderParameters::sPrototype))
		val = ((CirclesGridFinderParameters*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("CirclesGridFinderParameters"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::TrackerMIL::Params& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(TrackerMIL_Params::sPrototype))
		val = ((TrackerMIL_Params*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("TrackerMIL::Params"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::QRCodeEncoder::Params& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(QRCodeEncoder_Params::sPrototype))
		val = ((QRCodeEncoder_Params*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("QRCodeEncoder::Params"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::TrackerGOTURN::Params& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(TrackerGOTURN_Params::sPrototype))
		val = ((TrackerGOTURN_Params*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("TrackerGOTURN::Params"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::TrackerDaSiamRPN::Params& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(TrackerDaSiamRPN_Params::sPrototype))
		val = ((TrackerDaSiamRPN_Params*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("TrackerDaSiamRPN::Params"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::SimpleBlobDetector::Params& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(SimpleBlobDetector_Params::sPrototype))
		val = ((SimpleBlobDetector_Params*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("SimpleBlobDetector::Params"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::detail::CameraParams& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(detail_CameraParams::sPrototype))
		val = ((detail_CameraParams*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("detail::CameraParams"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::detail::ImageFeatures& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(detail_ImageFeatures::sPrototype))
		val = ((detail_ImageFeatures*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("detail::ImageFeatures"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::detail::MatchesInfo& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(detail_MatchesInfo::sPrototype))
		val = ((detail_MatchesInfo*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("detail::MatchesInfo"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::dnn::DictValue& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(dnn_DictValue::sPrototype))
		val = ((dnn_DictValue*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("dnn::DictValue"), token);
	return CONDITION_TRUE;
}

#ifdef HAS_GAPI
ResultType TokenToVal(ExprTokenType &token, cv::gapi::GNetParam &val, char ignore) {
	IObject *obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(gapi_GNetParam::sPrototype))
		val = ((gapi_GNetParam *)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("gapi::GNetParam"), token);
	return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::GOpaque<cv::Rect>*& val, char ignore) {
		IObject* obj;
		TokenToObject(token, obj, nullptr);
		if (obj && obj->IsOfType(GOpaque_Rect::sPrototype))
			val = &((GOpaque_Rect*)obj)->mC;
		else if (!ignore)
			return g_ahkapi->TypeError(_T("GOpaque_Rect"), token);
			return CONDITION_TRUE;
}

ResultType TokenToVal(ExprTokenType& token, cv::GOpaque<cv::Size>*& val, char ignore) {
		IObject* obj;
		TokenToObject(token, obj, nullptr);
		if (obj && obj->IsOfType(GOpaque_Size::sPrototype))
			val = &((GOpaque_Size*)obj)->mC;
		else if (!ignore)
			return g_ahkapi->TypeError(_T("GOpaque_Size"), token);
			return CONDITION_TRUE;
}
#endif

ResultType ArrayToBin(Array* arr, char* pval, char* def, char ignore) {
	char c, n;
	union {
		char* pc;
		uchar* puc;
		short* ps;
		ushort* pus;
		int* pi;
		uint* pui;
		__int64* pi6;
		float* pf;
		double* pd;
		size_t* put;
		INT_PTR* pt;
		cv::String* pstr;
	};
	ExprTokenType tmp;
	cv::String str;
	pc = pval;
	for (UINT i=0; c = def[i]; i++) {
		if (i < arr->mLength) {
			auto& it = arr->mItem[i];
			if (it.symbol == SYM_MISSING) {
				if (c == 's')
					str = "";
				else tmp.SetValue(0);
			}
			else {
				tmp.symbol = it.symbol, tmp.value_int64 = it.n_int64;
				if (c == 's') {
					if (tmp.symbol == SYM_OBJECT && !ignore)
						return g_ahkapi->TypeError(_T("String"), tmp);
					TokenToVal(tmp, str);
				}
				else if (!g_ahkapi->TokenToNumber(tmp, tmp))
					if (ignore)
						tmp.SetValue(0);
					else return g_ahkapi->TypeError(_T("Number"), tmp);
				else if (c == 'f' || c == 'd') {
					if (tmp.symbol == SYM_INTEGER)
						tmp.value_double = (double)tmp.value_int64;
				} else if (tmp.symbol == SYM_FLOAT)
					tmp.value_int64 = (__int64)tmp.value_double;
			}
		}
		else if (c == 's')
			str = "";
		else tmp.SetValue(0);
		switch (c)
		{
		case 'c':
			*pc = (char)tmp.value_int64; pc++; break;
		case 'C':
			*puc = (uchar)tmp.value_int64; puc++; break;
		case 'h':
			if ((pc - pval) % 2)pc++;
			*ps = (short)tmp.value_int64; ps++; break;
		case 'H':
			if ((pc - pval) % 2)pc++;
			*pus = (ushort)tmp.value_int64; pus++; break;
		case 'i':
			if (n = (pc - pval) % 4) pc += 4 - n;
			*pi = (int)tmp.value_int64; pi++; break;
		case 'I':
			if (n = (pc - pval) % 4) pc += 4 - n;
			*pui = (uint)tmp.value_int64; pui++; break;
		case 'f':
			if (n = (pc - pval) % 4) pc += 4 - n;
			*pf = (float)tmp.value_double; pf++; break;
		case 'd':
			if (n = (pc - pval) % 8) pc += 8 - n;
			*pd = tmp.value_double; pd++; break;
		case '6':
			if (n = (pc - pval) % 8) pc += 8 - n;
			*pi6 = tmp.value_int64; pi6++; break;
		case 't':
			if (n = (pc - pval) % sizeof(void*)) pc += sizeof(void*) - n;
			*pt = (INT_PTR)tmp.value_int64; pt++; break;
		case 'T':
			if (n = (pc - pval) % sizeof(void*)) pc += sizeof(void*) - n;
			*put = (size_t)tmp.value_int64; put++; break;
		case 's':
			if (n = (pc - pval) % sizeof(void*)) pc += sizeof(void*) - n;
			*pstr = str;
			pstr++; break;
		default:
			break;
		}
	}
	return CONDITION_TRUE;
}

Array* BinToArray(char* pval, char* def) {
	ResultToken p{};
	union {
		char* pc;
		uchar* puc;
		short* ps;
		ushort* pus;
		int* pi;
		uint* pui;
		__int64* pi6;
		float* pf;
		double* pd;
		size_t* put;
		INT_PTR* pt;
		cv::String* pstr;
	};
	pc = pval;
	char c, n;
	int i;
	Array* arr = (Array*)g_ahkapi->Object_New(IAhkApi::ObjectType::Array);
	for (i = 0; c = def[i]; i++) {
		switch (c)
		{
		case 'c':
			p.SetValue((__int64)*pc); pc++; break;
		case 'C':
			p.SetValue((__int64)*puc); puc++; break;
		case 'h':
			if ((pc - pval) % 2)pc++;
			p.SetValue((__int64)*ps); ps++; break;
		case 'H':
			if ((pc - pval) % 2)pc++;
			p.SetValue((__int64)*pus); pus++; break;
		case 'i':
			if (n = (pc - pval) % 4) pc += 4 - n;
			p.SetValue((__int64)*pi); pi++; break;
		case 'I':
			if (n = (pc - pval) % 4) pc += 4 - n;
			p.SetValue((__int64)*pui); pui++; break;
		case 'f':
			if (n = (pc - pval) % 4) pc += 4 - n;
			p.SetValue((double)*pf); pf++; break;
		case 'd':
			if (n = (pc - pval) % 8) pc += 8 - n;
			p.SetValue(*pd); pd++; break;
		case '6':
			if (n = (pc - pval) % 8) pc += 8 - n;
			p.SetValue(*pi6); pi6++; break;
		case 't':
			if (n = (pc - pval) % sizeof(void*)) pc += sizeof(void*) - n;
			p.SetValue((__int64)*pt); pt++; break;
		case 'T':
			if (n = (pc - pval) % sizeof(void*)) pc += sizeof(void*) - n;
			p.SetValue((__int64)*put); put++; break;
		case 's':
			if (n = (pc - pval) % sizeof(void*)) pc += sizeof(void*) - n;
			ValToResult(*pstr, p);
			pstr++; break;
		default:
			break;
		}
		g_ahkapi->Array_InsertItem(arr, p);
		if (p.mem_to_free)
			free(p.mem_to_free), p.mem_to_free = nullptr;
	}
	return arr;
}

#define TokenToPtr(cls) ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::cls>& val, char ignore) {\
	IObject* obj;\
	TokenToObject(token, obj, nullptr);\
	if (obj && obj->IsOfType(cls::sPrototype))\
		val = ((cls*)obj)->mC;\
	else if (!ignore)\
		return g_ahkapi->TypeError(_T(#cls), token);\
	return CONDITION_TRUE;\
}

#define TokenTo(cls) ResultType TokenToVal(ExprTokenType& token, cv::cls*& val, char ignore) {\
	IObject* obj;\
	TokenToObject(token, obj, nullptr);\
	if (obj && obj->IsOfType(cls::sPrototype))\
		val = ((cls*)obj)->mC.get();\
	else if (!ignore)\
		return g_ahkapi->TypeError(_T(#cls), token);\
	return CONDITION_TRUE;\
}

TokenToPtr(Feature2D)
TokenToPtr(DescriptorMatcher)
TokenTo(FileNode)
TokenToPtr(FileStorage)
TokenTo(KeyPoint)
TokenTo(Moments)
TokenTo(RNG)
#ifdef HAS_GAPI
TokenTo(GMat)
TokenTo(GScalar)
#endif


#define TokenToPtr_(cls) ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::cls>& val, char ignore)
#define TokenTo_(cls) ResultType TokenToVal(ExprTokenType& token, cv::cls*& val, char ignore)
TokenToPtr_(ml::ParamGrid) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(ml_ParamGrid::sPrototype))
		val = ((ml_ParamGrid*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("ml::ParamGrid"), token);
	return CONDITION_TRUE;
}

TokenToPtr_(ml::TrainData) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(ml_TrainData::sPrototype))
		val = ((ml_TrainData*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("ml::TrainData"), token);
	return CONDITION_TRUE;
}
TokenToPtr_(cuda::GpuMat::Allocator) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(cuda_GpuMat_Allocator::sPrototype))
		val = ((cuda_GpuMat_Allocator*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("cuda::GpuMat::Allocator"), token);
	return CONDITION_TRUE;
}
TokenTo_(dnn::Net) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(dnn_Net::sPrototype))
		val = ((dnn_Net*)obj)->mC.get();
	else if (!ignore)
		return g_ahkapi->TypeError(_T("dnn::Net"), token);
	return CONDITION_TRUE;
}
TokenTo_(cuda::Event) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(cuda_Event::sPrototype))
		val = ((cuda_Event*)obj)->mC.get();
	else if (!ignore)
		return g_ahkapi->TypeError(_T("cuda::Event"), token);
	return CONDITION_TRUE;
}
TokenTo_(cuda::Stream) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(cuda_Stream::sPrototype))
		val = ((cuda_Stream*)obj)->mC.get();
	else if (!ignore)
		return g_ahkapi->TypeError(_T("cuda::Stream"), token);
	return CONDITION_TRUE;
}
TokenTo_(cuda::HostMem) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(cuda_HostMem::sPrototype))
		val = &((cuda_HostMem*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("cuda::HostMem"), token);
	return CONDITION_TRUE;
}
TokenTo_(cuda::GpuMat) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(cuda_GpuMat::sPrototype))
		val = &((cuda_GpuMat*)obj)->mC;
	else if (!ignore)
		return g_ahkapi->TypeError(_T("cuda::GpuMat"), token);
	return CONDITION_TRUE;
}
TokenTo_(cuda::GpuMat::Allocator) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (obj && obj->IsOfType(cuda_GpuMat_Allocator::sPrototype))
		val = ((cuda_GpuMat_Allocator*)obj)->mC.get();
	else if (!ignore)
		return g_ahkapi->TypeError(_T("cuda::GpuMat::Allocator"), token);
	return CONDITION_TRUE;
}



ResultType TokenToVal(ExprTokenType& token, std::vector<uchar>& val, char ignore) { return TokenToVector(token, (std::vector<char>&)val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<char>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<char>>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<int>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<int>>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<float>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<double>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::String>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Mat>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::UMat>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::KeyPoint>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::DMatch>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<cv::DMatch>>& val, char ignore) { return TokenToVector(token, val, ignore); }
#ifdef HAS_GAPI
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::gapi::GNetParam>& val, char ignore) { return TokenToVector(token, val, ignore); }
#endif
ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<cv::KeyPoint>>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Size>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Rect>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Rect2d>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::RotatedRect>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Point>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<cv::Point>>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<cv::Point2f>>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Point2f>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::detail::CameraParams>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::detail::ImageFeatures>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::detail::MatchesInfo>& val, char ignore) { return TokenToVector(token, val, ignore); }

ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec2b>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec2d>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec2f>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec2i>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec2s>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec2w>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec3b>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec3d>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec3f>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec3i>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec3s>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec3w>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec4b>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec4d>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec4f>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec4i>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec4s>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec4w>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec6d>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec6f>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec6i>& val, char ignore) { return TokenToVector(token, val, ignore); }
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Vec8i>& val, char ignore) { return TokenToVector(token, val, ignore); }


inline void ValToResult(int val, ResultToken& result) {
	result.SetValue((__int64)val);
}

void ValToResult(__int64 val, ResultToken& result) {
	result.SetValue((__int64)val);
}

inline void ValToResult(double val, ResultToken& result) {
	result.SetValue(val);
}

inline void ValToResult(float val, ResultToken& result) {
	result.SetValue((double)val);
}

void ValToResult(std::vector<uchar>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<int>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<std::vector<int>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<std::vector<std::vector<int>>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<double>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<float>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(cv::Scalar& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec2b& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec2d& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec2f& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec2i& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec2s& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec2w& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec3b& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec3d& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec3f& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec3i& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec3s& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec3w& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec4b& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec4d& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec4f& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec4i& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec4s& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec4w& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec6d& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec6f& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec6i& val, ResultToken& result) { return VecToResult(val, result); }
void ValToResult(cv::Vec8i& val, ResultToken& result) { return VecToResult(val, result); }

void ValToResult(std::vector<cv::Vec2b>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec2d>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec2f>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec2i>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec2s>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec2w>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec3b>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec3d>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec3f>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec3i>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec3s>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec3w>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec4b>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec4d>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec4f>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec4i>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec4s>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec4w>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec6d>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec6f>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec6i>& val, ResultToken& result) { return VectorToResult(val, result); }
void ValToResult(std::vector<cv::Vec8i>& val, ResultToken& result) { return VectorToResult(val, result); }


void ValToResult(cv::TermCriteria& val, ResultToken& result) {
	ExprTokenType p[3], * param[3] = { p,p + 1,p + 2 };
	p[0].SetValue(val.type);
	p[1].SetValue(val.maxCount);
	p[2].SetValue(val.epsilon);
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 3));
}

void ValToResult(cv::DMatch& val, ResultToken& result) {
	ExprTokenType p[4], * param[4] = { p,p + 1,p + 2,p + 3 };
	p[0].SetValue(val.queryIdx);
	p[1].SetValue(val.trainIdx);
	p[2].SetValue(val.imgIdx);
	p[3].SetValue(val.distance);
	result.SetValue(DMatch::sPrototype->New(param, 4));
}

void ValToResult(cv::Mat& val, ResultToken& result) {
	result.SetValue(Mat::sPrototype->New(nullptr, 0));
	((Mat*)result.object)->mC = val;
}

void ValToResult(cv::UMat& val, ResultToken& result) {
	result.SetValue(UMat::sPrototype->New(nullptr, 0));
	((UMat*)result.object)->mC = val;
}

void ValToResult(cv::FileNode& val, ResultToken& result) {
	result.SetValue(FileNode::sPrototype->New(nullptr, 0));
	*((FileNode*)result.object)->mC = val;
}

void ValToResult(cv::KeyPoint& val, ResultToken& result) {
	result.SetValue(KeyPoint::sPrototype->New(nullptr, 0));
	*((KeyPoint*)result.object)->mC = val;
}

void ValToResult(cv::detail::MatchesInfo& val, ResultToken& result) {
	result.SetValue(detail_MatchesInfo::sPrototype->New(nullptr, 0));
	((detail_MatchesInfo*)result.object)->mC = val;
}

void ValToResult(cv::detail::CameraParams& val, ResultToken& result) {
	result.SetValue(detail_CameraParams::sPrototype->New(nullptr, 0));
	((detail_CameraParams*)result.object)->mC = val;
}

void ValToResult(cv::Point2f* val, ResultToken& result) {
	ValToResult(*val, result);
}

void ValToResult(cv::Point2d& val, ResultToken& result) {
	ExprTokenType p[2];
	ExprTokenType* param[] = { p,p + 1 };
	p->SetValue(val.x);
	p[1].SetValue(val.y);
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 2));
}

void ValToResult(cv::Point2f& val, ResultToken& result) {
	ExprTokenType p[2];
	ExprTokenType* param[] = { p,p + 1 };
	p->SetValue((double)val.x);
	p[1].SetValue((double)val.y);
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 2));
}

void ValToResult(cv::Point& val, ResultToken& result) {
	ExprTokenType p[2] = { (__int64)val.x,(__int64)val.y };
	ExprTokenType* param[] = { p,p + 1 };
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 2));
}

void ValToResult(cv::Size& val, ResultToken& result) {
	ExprTokenType p[2];
	ExprTokenType* param[] = { p,p + 1 };
	p[0].SetValue(val.width);
	p[1].SetValue(val.height);
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 2));
}

void ValToResult(cv::Size2f& val, ResultToken& result) {
	ExprTokenType p[2];
	p->SetValue(val.width);
	p[1].SetValue(val.height);
	ExprTokenType* param[] = { p,p + 1 };
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 2));
}

void ValToResult(cv::Rect& val, ResultToken& result) {
	ExprTokenType p[4];
	ExprTokenType* param[] = { p,p + 1,p + 2,p + 3 };
	p[0].SetValue(val.x);
	p[1].SetValue(val.y);
	p[2].SetValue(val.width);
	p[3].SetValue(val.height);
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 4));
}

void ValToResult(cv::Rect2d& val, ResultToken& result) {
	ExprTokenType p[4];
	ExprTokenType* param[] = { p,p + 1,p + 2,p + 3 };
	p[0].SetValue(val.x);
	p[1].SetValue(val.y);
	p[2].SetValue(val.width);
	p[3].SetValue(val.height);
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 4));
}

void ValToResult(cv::String& val, ResultToken& result) {
	result.symbol = SYM_STRING;
#ifdef _UNICODE
	auto len = MultiByteToWideChar(CP_ACP, 0, val.data(), (int)val.size(), NULL, 0);
	result.marker_length = len;
	result.marker = result.mem_to_free = (LPTSTR)malloc((len + 1) << 1);
	MultiByteToWideChar(CP_ACP, 0, val.data(), (int)val.size(), result.marker, len + 1);
	result.marker[len] = '\0';
#else
	result.marker_length = val.size() + 1;
	result.marker = result.mem_to_free = (char*)malloc(result.marker_length);
	memcpy(result.marker, val.data(), val.size());
	result.marker[val.size()] = '\0';
#endif // _UNICODE
}

void ValToResult(cv::RotatedRect& val, ResultToken& result) {
	result.SetValue(BinToArray((char*)&val, "fffff"));
}

void ValToResult(cv::detail::ImageFeatures& val, ResultToken& result) {
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, nullptr, 0));
	ResultToken t{};
	t.SetValue(val.img_idx);
	g_ahkapi->Array_InsertItem((Array*)result.object, t);
	ValToResult(val.img_size, t);
	g_ahkapi->Array_InsertItem((Array*)result.object, t);
	t.object->Release();
	ValToResult(val.keypoints, t);
	g_ahkapi->Array_InsertItem((Array*)result.object, t);
	t.object->Release();
	ValToResult(val.descriptors, t);
	g_ahkapi->Array_InsertItem((Array*)result.object, t);
	t.object->Release();
}

#ifdef HAS_GAPI
void ValToResult(cv::gapi::core::GMat2& val, ResultToken& result) {
	auto m1 = (GMat*)GMat::sPrototype->New(nullptr, 0);
	auto m2 = (GMat*)GMat::sPrototype->New(nullptr, 0);
	m1->mC = cv::makePtr<cv::GMat>(std::get<0>(val));
	m2->mC = cv::makePtr<cv::GMat>(std::get<1>(val));
	ExprTokenType p1(m1), p2(m2);
	ExprTokenType* param[] = { &p1,&p2 };
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 2));
}

void ValToResult(cv::gapi::core::GMat3& val, ResultToken& result) {
	auto m1 = (GMat*)GMat::sPrototype->New(nullptr, 0);
	auto m2 = (GMat*)GMat::sPrototype->New(nullptr, 0);
	auto m3 = (GMat*)GMat::sPrototype->New(nullptr, 0);
	m1->mC = cv::makePtr<cv::GMat>(std::get<0>(val));
	m2->mC = cv::makePtr<cv::GMat>(std::get<1>(val));
	m3->mC = cv::makePtr<cv::GMat>(std::get<2>(val));
	ExprTokenType p1(m1), p2(m2), p3(m3);
	ExprTokenType* param[] = { &p1,&p2,&p3 };
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 3));
}

void ValToResult(cv::gapi::core::GMatScalar& val, ResultToken& result) {
	auto m1 = (GMat*)GMat::sPrototype->New(nullptr, 0);
	auto m2 = (GScalar*)GScalar::sPrototype->New(nullptr, 0);
	m1->mC = cv::makePtr<cv::GMat>(std::get<0>(val));
	m2->mC = cv::makePtr<cv::GScalar>(std::get<1>(val));
	ExprTokenType p1(m1), p2(m2);
	ExprTokenType* param[] = { &p1,&p2 };
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, 2));
}
#endif

void ValToResult(std::vector<std::vector<cv::Vec4i>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::DMatch>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<std::vector<cv::DMatch>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::Rect>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::Rect2d>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::String>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::Size>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::Point2f>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::Point>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<std::vector<cv::Point>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<std::vector<cv::Point2f>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::KeyPoint>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<std::vector<cv::KeyPoint>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::Mat>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::UMat>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<std::vector<cv::Mat>>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::RotatedRect>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::detail::ImageFeatures>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::detail::MatchesInfo>& val, ResultToken& result) { return VectorToResult(val, result); }

void ValToResult(std::vector<cv::detail::CameraParams>& val, ResultToken& result) { return VectorToResult(val, result); }

Object* register_vector[] = {
	Vector<double>::sPrototype,
	Vector<float>::sPrototype,
	Vector<int>::sPrototype,
	Vector<cv::Mat>::sPrototype,
	Vector<cv::Point>::sPrototype,
	Vector<cv::Point2f>::sPrototype,
	Vector<cv::Rect>::sPrototype,
	Vector<cv::Rect2d>::sPrototype,
	Vector<cv::RotatedRect>::sPrototype,
	Vector<cv::Size>::sPrototype,
	Vector<uchar>::sPrototype,
	Vector<cv::UMat>::sPrototype,
	Vector<cv::Vec2b>::sPrototype,
	Vector<cv::Vec2d>::sPrototype,
	Vector<cv::Vec2f>::sPrototype,
	Vector<cv::Vec2i>::sPrototype,
	Vector<cv::Vec2s>::sPrototype,
	Vector<cv::Vec2w>::sPrototype,
	Vector<cv::Vec3b>::sPrototype,
	Vector<cv::Vec3d>::sPrototype,
	Vector<cv::Vec3f>::sPrototype,
	Vector<cv::Vec3i>::sPrototype,
	Vector<cv::Vec3s>::sPrototype,
	Vector<cv::Vec3w>::sPrototype,
	Vector<cv::Vec4b>::sPrototype,
	Vector<cv::Vec4d>::sPrototype,
	Vector<cv::Vec4f>::sPrototype,
	Vector<cv::Vec4i>::sPrototype,
	Vector<cv::Vec4s>::sPrototype,
	Vector<cv::Vec4w>::sPrototype,
	Vector<cv::Vec6d>::sPrototype,
	Vector<cv::Vec6f>::sPrototype,
	Vector<cv::Vec6i>::sPrototype,
	Vector<cv::Vec8i>::sPrototype,
	Vector<std::vector<int>>::sPrototype,
	Vector<std::vector<cv::Point>>::sPrototype,
	Vector<std::vector<cv::Point2f>>::sPrototype,
};

template<typename T>
inline ResultType TokenToVector(ExprTokenType& token, std::vector<T>& val, char ignore) {
	IObject* obj;
	Array* arr = dynamic_cast<Array*>(obj = TokenToObject(token));
	if (!arr) {
		if (ignore && token.symbol == SYM_MISSING)
			return CONDITION_TRUE;
		__if_exists(Vector<T>) {
			if (dynamic_cast<Object*>(obj)) {
				if (((Object*)obj)->mBase == Vector<T>::sPrototype) {
					val = *(std::vector<T>*)((Vector<T>*)obj)->mPtr;
					return CONDITION_TRUE;
				}
				TCHAR name[256]{};
				int i = 0;
				for (auto t = typeid(val).name(); t[i]; i++)name[i] = t[i];
				return g_ahkapi->TypeError(name, token);
			}
		}
		return g_ahkapi->TypeError(_T("Array"), token);
	}
	val.resize(arr->mLength);
	if (auto l = arr->mLength) {
		auto& its = arr->mItem;
		ExprTokenType tk;
		for (UINT i = 0; i < l; i++) {
			auto& it = its[i];
			tk.symbol = it.symbol, tk.value_int64 = it.n_int64;
			ResultType result = TokenToVal(tk, val[i], ignore);
			if (result != CONDITION_TRUE)
				return result;
		}
	}
	return CONDITION_TRUE;
}

template<typename T>
inline void VectorToResult(std::vector<T>& val, ResultToken& result, bool toArray) {
	__if_exists(Vector<T>) {
		if (Vector<T>::sPrototype && !toArray) {
			auto obj = (Vector<T>*)Vector<T>::sPrototype->New(g_invalidparam, 1);
			obj->mC = val;
			result.SetValue(obj);
			return;
		}
	}
	result.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, nullptr, 0));
	Array* arr = (Array*)result.object;
	ResultToken t{};
	auto size = val.size();
	if (!size)return;
	else if (size > 1)
		g_ahkapi->Object_SetProp(arr, _T("Capacity"), ExprTokenType((__int64)val.size()));
	for (auto& it : val) {
		ValToResult(it, t);
		g_ahkapi->Array_InsertItem(arr, t);
		if (t.symbol == SYM_OBJECT)
			t.object->Release();
		else if (t.symbol == SYM_STRING)
			free(t.mem_to_free);
	}	
}