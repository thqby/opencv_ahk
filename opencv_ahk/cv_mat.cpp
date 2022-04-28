#include "pch.h"
#include "cv_mat.h"
#include "util.h"


thread_local IAhkApi::Prototype* Mat::sPrototype = nullptr;

void Mat::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount)
{
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___New: {
		new (&mC) cv::Mat;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		if (aParamCount >= 3) {
			__int64 _rows, _cols, _type, _data = 0;
			size_t _step = 0;
			if (ParamIndexToVal(0, _rows) || ParamIndexToVal(1, _cols) || ParamIndexToVal(2, _type))
				_o_return_result;
			if (aParamCount > 3)
				_data = TokenToInt64(*aParam[3]);
			if (aParamCount > 4)
				_step = (size_t)TokenToInt64(*aParam[4]);
			if (_rows * _cols == 0) {
				aResultToken.result = g_ahkapi->Error(_T("invalid param"), _T("rows or cols cannot be 0"));
				return;
			}
			if (!_data) {
				if (aParamCount > 3) {
					double arr[4];
					auto a = dynamic_cast<Array*>(TokenToObject(*aParam[3]));
					if (!a || !ArrayToCArr(a, arr, 4)) {
						if (a)
							__result = g_ahkapi->Error(_T("invalid param"), _T("param 4 is not an array of numbers"));
						else __result = g_ahkapi->TypeError(_T("Array"), *aParam[3]);
						_o_return_result;
					}
					cv::Scalar sc(arr[0], arr[1], arr[2], arr[3]);
					new (&mC) cv::Mat((int)_rows, (int)_cols, (int)_type, sc);
				}
				else
					new (&mC) cv::Mat((int)_rows, (int)_cols, (int)_type);
			}
			else {
				if (_data < 65536) {
					aResultToken.result = g_ahkapi->Error(_T("invalid memory address"));
					return;
				}
				new (&mC) cv::Mat((int)_rows, (int)_cols, (int)_type, (void*)_data, _step);
			}
		}
		else if (aParamCount == 2) {
			cv::Mat obj1;
			if ((__result = TokenToVal(*aParam[0], obj1)) != CONDITION_TRUE)
				_o_return_result;
			auto obj2 = dynamic_cast<Array*>(TokenToObject(*aParam[1]));
			cv::Rect roi;
			if (!obj2 || !ArrayToCArr(obj2, (int*)&roi, 4)) {
				if (obj2)
					__result = g_ahkapi->Error(_T("invalid param"), _T("param 2 is not an array of numbers"));
				else __result = g_ahkapi->TypeError(_T("Array"), *aParam[1]);
				_o_return_result;
			}
			new (&mC) cv::Mat(obj1, roi);
		}
		else
			aResultToken.result = g_ahkapi->Error(_T("invalid param count"));
		return;
	}
	case M___Delete:
		mC.~Mat();
		break;
	case M_Call: {
		auto obj = dynamic_cast<Array*>(TokenToObject(*aParam[0]));
		cv::Rect roi;
		if (!obj || !ArrayToCArr(obj, (int*)&roi, 4)) {
			if (obj)
				aResultToken.result = g_ahkapi->Error(_T("invalid param"), _T("param 1 is not an array of numbers"));
			else aResultToken.result = g_ahkapi->TypeError(_T("Array"), *aParam[0]);
		}
		else {
			auto m = (Mat*)sPrototype->New(nullptr, 0);
			m->mC = mC(roi);
			aResultToken.SetValue(m);
		}
		return;
	}
	case P___Item: {
		ExprTokenType val;
		if (aFlags & IT_SET) {
			if (aParamCount == 1) {
				cv::Scalar sc{};
				if (ParamIndexToVal(0, sc))
					_o_return_result;
				mC = sc;
				return;
			}
			val = *aParam[0];
			aParam++, aParamCount--;
		}
		if (aParamCount < mC.dims) {
			aResultToken.result = g_ahkapi->Error(_T("invalid param count"));
			return;
		}
		__int64 p1, p2, p3;
		if (ParamIndexToVal(0, p1) || ParamIndexToVal(1, p2))
			_o_return_result;
		uchar* p;
		auto si = mC.channels();
		auto si1 = mC.elemSize1();
		auto tp = mC.type() & 7;
		if (aParamCount > 2) {
			if (ParamIndexToVal(2, p3))
				_o_return_result;
			p = mC.ptr((int)p1, (int)p2) + si1 * p3;
			si = 1;
		}
		else
			p = mC.ptr((int)p1, (int)p2);
		if (aFlags & IT_SET) {
			union {
				double* dous;
				int* ints;
			};
			dous = (double*)_alloca(si * si1);
			if (si == 1) {
				if (!g_ahkapi->TokenToNumber(val, val)) {
					aResultToken.result = g_ahkapi->TypeError(_T("Number"), val);
					return;
				}
				if (tp >= CV_32F)
					dous[0] = val.symbol == SYM_INTEGER ? (double)val.value_int64 : val.value_double;
				else
					ints[0] = val.symbol == SYM_INTEGER ? (int)val.value_int64 : (int)val.value_double;
			}
			else {
				Array* arr = nullptr;
				if (!(arr = dynamic_cast<Array*>(TokenToObject(val))))
					return (void)(aResultToken.result = g_ahkapi->TypeError(_T("Array"), val));
				if ((tp >= CV_32F && !ArrayToCArr(arr, dous, si)) || !ArrayToCArr(arr, ints, si))
					return (void)(aResultToken.result = g_ahkapi->Error(_T("invalid param"), _T("param 1 is not an array of numbers")));
			}
			switch (tp)
			{
			case CV_8S:
				for (int i = 0; i < si; i++, p += si1)
					*(schar*)p = ints[i];
				return;
			case CV_8U:
				for (int i = 0; i < si; i++, p += si1)
					*(uchar*)p = ints[i];
				return;
			case CV_16S:
				for (int i = 0; i < si; i++, p += si1)
					*(short*)p = ints[i];
				return;
			case CV_16U:
				for (int i = 0; i < si; i++, p += si1)
					*(ushort*)p = ints[i];
				return;
			case CV_32S:
				for (int i = 0; i < si; i++, p += si1)
					*(int*)p = ints[i];
				return;
			case CV_32F:
				for (int i = 0; i < si; i++, p += si1)
					*(float*)p = (float)dous[i];
				return;
			case CV_64F:
				for (int i = 0; i < si; i++, p += si1)
					*(double*)p = dous[i];
				return;
			}
		}
		else {
			ExprTokenType* vals = (ExprTokenType*)_alloca((sizeof(ExprTokenType) + sizeof(ExprTokenType*)) * si);
			ExprTokenType** param = (ExprTokenType**)(vals + si);
			for (int i = 0; i < si; i++, p += si1) {
				param[i] = &vals[i];
				switch (tp)
				{
				case CV_8S:
					vals[i].SetValue(*(schar*)p);
					break;
				case CV_8U:
					vals[i].SetValue(*(uchar*)p);
					break;
				case CV_16S:
					vals[i].SetValue(*(short*)p);
					break;
				case CV_16U:
					vals[i].SetValue(*(ushort*)p);
					break;
				case CV_32S:
					vals[i].SetValue(*(int*)p);
					break;
				case CV_32F:
					vals[i].SetValue(*(float*)p);
					break;
				case CV_64F:
					vals[i].SetValue(*(double*)p);
					break;
				}
			}
			if (si > 1)
				aResultToken.SetValue(g_ahkapi->Object_New(IAhkApi::ObjectType::Array, param, si));
			else
				aResultToken.symbol = vals[0].symbol, aResultToken.value_int64 = vals[0].value_int64;
			return;
		}
		return;
	}
	case P_ptr:
	case P_total:
		aResultToken.SetValue(aID == P_ptr ? (__int64)&mC : (__int64)mC.total());
		return;
	case P_type:
	case P_channels:
	case P_depth:
		aResultToken.SetValue(aID == P_type ? mC.type() : aID == P_channels ? mC.channels() : mC.depth());
		return;
	case P_empty:
		aResultToken.SetValue(mC.empty());
		return;
	case P_dims:
	case P_cols:
	case P_rows:
		aResultToken.SetValue(aID == P_rows ? mC.rows : aID == P_cols ? mC.cols : mC.dims);
		return;
	case P_elemSize:
	case P_elemSize1:
		aResultToken.SetValue((__int64)(aID == P_elemSize ? mC.elemSize() : mC.elemSize1()));
		return;
	case P_isContinuous:
	case P_isSubmatrix:
		aResultToken.SetValue((__int64)(aID == P_isContinuous ? mC.isContinuous() : mC.isSubmatrix()));
		return;
	case M_getUMat: {
		__int64 acc, flag = 0;
		if (ParamIndexToVal(0, acc) || (aParamCount > 1 && ParamIndexToVal(1, flag, 2)))
			_o_return_result;
		auto mat = (UMat*)UMat::sPrototype->New(nullptr, 0);
		mat->mC = mC.getUMat((cv::AccessFlag)acc, (cv::UMatUsageFlags)flag);
		aResultToken.SetValue(mat);
		return;
	}
	case M_adjustROI: {
		__int64 top, bottom, left, right;
		if (ParamIndexToVal(0, top) || ParamIndexToVal(1, bottom) || ParamIndexToVal(2, left) || ParamIndexToVal(3, right))
			_o_return_result;
		mC.adjustROI((int)top, (int)bottom, (int)left, (int)right);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_locateROI: {
		VarRef* v1, *v2;
		if ((__result = TokenToVal(*aParam[0], v1)) != CONDITION_TRUE || (__result = TokenToVal(*aParam[1], v2)) != CONDITION_TRUE)
			_o_return_result;
		cv::Size size;
		cv::Point pos;
		mC.locateROI(size, pos);
		ExprTokenType param[2], temp, * params[] = { param,param + 1 };
		param[0].SetValue(size.width), param[1].SetValue(size.height);
		temp = g_ahkapi->Object_New(IAhkApi::ObjectType::Array, params, 2);
		g_ahkapi->VarAssign(v1, temp), temp.object->Release();
		param[0].SetValue(pos.x), param[1].SetValue(pos.y);
		temp = g_ahkapi->Object_New(IAhkApi::ObjectType::Array, params, 2);
		g_ahkapi->VarAssign(v1, temp), temp.object->Release();
		return;
	}
	case M_setTo:
	case M_copyTo:
	case M_convertTo: {
		cv::_OutputArray m;
		cv::_InputArray mask = cv::noArray();
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (aID == M_convertTo)
			mC.convertTo(m, (int)TokenToInt64(*aParam[1]), aParamCount > 2 ? TokenToDouble(*aParam[2]) : 1.0, aParamCount > 3 ? TokenToDouble(*aParam[3]) : 0.0);
		else {
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], mask);
			if (aID == M_setTo)
				mC.setTo(m, mask);
			else
				mC.copyTo(m, mask);
		}
		return;
	}
	case M_assignTo: {
		cv::Mat m;
		if ((__result = TokenToVal(*aParam[0], m)) == CONDITION_TRUE)
			mC.assignTo(m, aParamCount > 1 ? (int)TokenToInt64(*aParam[1]) : -1);
		else
			aResultToken.result = __result;
		return;
	}
	case M_mul:
	case M_dot: {
		cv::_InputArray m;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (aID == M_mul) {
			Mat* mm = (Mat*)sPrototype->New(nullptr, 0);
			mm->mC = mC.mul(m, aParamCount > 1 ? TokenToDouble(*aParam[1]) : 1.0);
			aResultToken.SetValue(mm);
		}
		else aResultToken.SetValue(mC.dot(m));
		return;
	}
	case M_reshape:
	case M_inv:
	case M_t: {
		auto m = (Mat*)sPrototype->New(nullptr, 0);
		if (aID == M_t)
			m->mC = mC.t();
		else if (aID == M_inv)
			m->mC = mC.inv(aParamCount ? (int)TokenToInt64(*aParam[0]) : 0);
		else
			m->mC = mC.reshape((int)TokenToInt64(*aParam[0]), aParamCount > 1 ? (int)TokenToInt64(*aParam[1]) : 0);
		aResultToken.SetValue(m);
		return;
	}
	case M_clone: {
		auto m = (Mat*)sPrototype->New(nullptr, 0);
		m->mC = mC.clone();
		aResultToken.SetValue(m);
		return;
	}
	case M_create: {
		__int64 _rows, _cols, _type;
		if (ParamIndexToVal(0, _rows) || ParamIndexToVal(1, _cols) || ParamIndexToVal(2, _type))
			_o_return_result;
		mC.create((int)_rows, (int)_cols, (int)_type);
		return;
	}
	case M_cross: {
		cv::_InputArray m;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		auto n = (Mat*)sPrototype->New(nullptr, 0);
		n->mC = mC.cross(m);
		aResultToken.SetValue(n);
		return;
	}
	case M_diag:
	case M_row:
	case M_col:
	case M_rowRange:
	case M_colRange: {
		auto mat = (Mat*)sPrototype->New(nullptr, 0);
		int p1 = (int)TokenToInt64(*aParam[0]);
		int p2 = aParamCount > 1 ? (int)TokenToInt64(*aParam[1]) : 0;
		if (aID == M_rowRange)
			mat->mC = mC.rowRange(p1, p2);
		else if (aID == M_colRange)
			mat->mC = mC.colRange((int)TokenToInt64(*aParam[0]), (int)TokenToInt64(*aParam[1]));
		else if (aID == M_row)
			mat->mC = mC.row((int)TokenToInt64(*aParam[0]));
		else if (aID == M_col)
			mat->mC = mC.col((int)TokenToInt64(*aParam[0]));
		else {
			if (auto obj = TokenToObject(*aParam[0])) {
				if (obj->IsOfType(Mat::sPrototype))
					mat->mC = cv::Mat::diag(((Mat*)obj)->mC);
				else {
					aResultToken.result = g_ahkapi->TypeError(_T("Mat"), *aParam[0]);
					return;
				}
			}
			else
				mat->mC = mC.diag((int)TokenToInt64(*aParam[0]));
		}
		aResultToken.SetValue(mat);
		return;
	}
	case M_step1:
		aResultToken.SetValue((__int64)mC.step1(aParamCount ? (int)TokenToInt64(*aParam[0]) : 0));
		return;
	case M_ptr: {
		__int64 p1 = 0, p2 = 0, p3 = 0;
		uchar* p;
		if ((aParamCount && ParamIndexToVal(0, p1, 2)) || (aParamCount > 1 && ParamIndexToVal(1, p2, 2)) ||
			(aParamCount > 2 && ParamIndexToVal(2, p3, 2)))
			_o_return_result;
		if (aParamCount > 2)
			p = mC.ptr((int)p1, (int)p2, (int)p3);
		else if (aParamCount == 2)
			p = mC.ptr((int)p1, (int)p2);
		else p = mC.ptr((int)p1);
		aResultToken.SetValue((__int64)p);
		return;
	}
	case M_eye:
	case M_ones:
	case M_zeros: {
		__int64 p1 = 0, p2 = 0, p3 = 0, p4 = 1;
		if (ParamIndexToVal(0, p1) || ParamIndexToVal(1, p2) || ParamIndexToVal(2, p3))
			_o_return_result;
		if (aID == M_ones) {
			if (aParamCount > 3 && ParamIndexToVal(3, p4, 2))
				_o_return_result;
			mC = cv::Mat::ones((int)p1, (int)p2, (int)p3) * (p4 ? (double)p4 : 1);
		}
		else if (aID == M_zeros)
			mC = cv::Mat::zeros((int)p1, (int)p2, (int)p3);
		else mC = cv::Mat::eye((int)p1, (int)p2, (int)p3);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_add:
	case M_subtract:
	case M_multiply:
	case M_divide: {
		ExprTokenType val;
		cv::MatExpr me;
		cv::Scalar sc{};
		bool is_invalid = true;
		if (aParam[0]->symbol == SYM_VAR)
			g_ahkapi->VarToToken(aParam[0]->var, val);
		else val = *aParam[0];
		if (val.symbol == SYM_OBJECT && val.object->Base() == Mat::sPrototype) {
			if (aID == M_add)
				me = mC + ((Mat*)val.object)->mC;
			else if (aID == M_subtract)
				me = mC - ((Mat*)val.object)->mC;
			else if (aID == M_multiply)
				me = mC * ((Mat*)val.object)->mC;
			else
				me = mC / ((Mat*)val.object)->mC;
		}
		else {
			if (val.symbol == SYM_OBJECT && dynamic_cast<Array*>(val.object)) {
				ResultType result;
				if ((result = TokenToVal(val, sc)) != CONDITION_TRUE)
					return (void)(aResultToken.result = result);
			}
			else if (g_ahkapi->TokenToNumber(val, val))
				sc = val.symbol == SYM_INTEGER ? (double)val.value_int64 : val.value_double;
			else return (void)(aResultToken.result = g_ahkapi->TypeError(val.symbol == SYM_OBJECT ? _T("Mat or Scalar") : _T("Number"), val));
			if (aID == M_add)
				me = mC + sc;
			else if (aID == M_subtract)
				me = mC - sc;
			else if (aID == M_multiply)
				me = mC * sc;
			else
				me = mC / sc;
		}
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = me;
		return (void)aResultToken.SetValue(__retval);
	}
	}
}


thread_local IAhkApi::Prototype* UMat::sPrototype = nullptr;

void UMat::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount)
{
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___New: {
		new (&mC) cv::UMat;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		if (aParamCount >= 3) {
			__int64 _rows, _cols, _type, _flag = 0;
			if (ParamIndexToVal(0, _rows) || ParamIndexToVal(1, _cols) || ParamIndexToVal(2, _type))
				_o_return_result;
			if (_rows * _cols == 0) {
				aResultToken.result = g_ahkapi->Error(_T("invalid param"), _T("rows or cols cannot be 0"));
				return;
			}
			if (aParamCount > 3) {
				double arr[4];
				IObject* obj;
				if (obj = TokenToObject(*aParam[3])) {
					auto a = dynamic_cast<Array*>(obj);
					if (!a || !ArrayToCArr(a, arr, 4)) {
						if (a)
							__result = g_ahkapi->Error(_T("invalid param"), _T("param 4 is not an array of numbers"));
						else __result = g_ahkapi->TypeError(_T("Array"), *aParam[3]);
						_o_return_result;
					}
					if (aParamCount > 4 && ParamIndexToVal(4, _flag, 2))
						_o_return_result;
				}
				else if (ParamIndexToVal(3, _flag))
					_o_return_result;
				if (obj) {
					cv::Scalar sc(arr[0], arr[1], arr[2], arr[3]);
					new (&mC) cv::UMat((int)_rows, (int)_cols, (int)_type, sc, (cv::UMatUsageFlags)_flag);
					return;
				}
			}
			new (&mC) cv::UMat((int)_rows, (int)_cols, (int)_type, (cv::UMatUsageFlags)_flag);
		}
		else if (aParamCount == 2) {
			cv::UMat obj1;
			if ((__result = TokenToVal(*aParam[0], obj1)) != CONDITION_TRUE)
				_o_return_result;
			auto obj2 = dynamic_cast<Array*>(TokenToObject(*aParam[1]));
			cv::Rect roi;
			if (!obj2 || !ArrayToCArr(obj2, (int*)&roi, 4)) {
				if (obj2)
					__result = g_ahkapi->Error(_T("invalid param"), _T("param 2 is not an array of numbers"));
				else __result = g_ahkapi->TypeError(_T("Array"), *aParam[1]);
				_o_return_result;
			}
			new (&mC) cv::UMat(obj1, roi);
		}
		else
			aResultToken.result = g_ahkapi->Error(_T("invalid param count"));
		return;
	}
	case M___Delete:
		mC.~UMat();
		break;
	case M_Call: {
		auto obj = dynamic_cast<Array*>(TokenToObject(*aParam[0]));
		cv::Rect roi;
		if (!obj || !ArrayToCArr(obj, (int*)&roi, 4)) {
			if (obj)
				aResultToken.result = g_ahkapi->Error(_T("invalid param"), _T("param 1 is not an array of numbers"));
			else aResultToken.result = g_ahkapi->TypeError(_T("Array"), *aParam[0]);
		}
		else {
			auto m = (UMat*)sPrototype->New(nullptr, 0);
			m->mC = mC(roi);
			aResultToken.SetValue(m);
		}
		return;
	}
	case P_ptr:
	case P_total:
		aResultToken.SetValue(aID == P_ptr ? (__int64)&mC : (__int64)mC.total());
		return;
	case P_type:
	case P_channels:
	case P_depth:
		aResultToken.SetValue(aID == P_type ? mC.type() : aID == P_channels ? mC.channels() : mC.depth());
		return;
	case P_empty:
		aResultToken.SetValue(mC.empty());
		return;
	case P_dims:
	case P_cols:
	case P_rows:
		aResultToken.SetValue(aID == P_rows ? mC.rows : aID == P_cols ? mC.cols : mC.dims);
		return;
	case P_elemSize:
	case P_elemSize1:
		aResultToken.SetValue((__int64)(aID == P_elemSize ? mC.elemSize() : mC.elemSize1()));
		return;
	case P_isContinuous:
	case P_isSubmatrix:
		aResultToken.SetValue((__int64)(aID == P_isContinuous ? mC.isContinuous() : mC.isSubmatrix()));
		return;
	case M_getMat: {
		__int64 acc;
		if (ParamIndexToVal(0, acc))
			_o_return_result;
		auto mat = (Mat*)Mat::sPrototype->New(nullptr, 0);
		mat->mC = mC.getMat((cv::AccessFlag)acc);
		aResultToken.SetValue(mat);
		return;
	}
	case M_adjustROI: {
		__int64 top, bottom, left, right;
		if (ParamIndexToVal(0, top) || ParamIndexToVal(1, bottom) || ParamIndexToVal(2, left) || ParamIndexToVal(3, right))
			_o_return_result;
		mC.adjustROI((int)top, (int)bottom, (int)left, (int)right);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_locateROI: {
		VarRef* v1, * v2;
		if ((__result = TokenToVal(*aParam[0], v1)) != CONDITION_TRUE || (__result = TokenToVal(*aParam[1], v2)) != CONDITION_TRUE)
			_o_return_result;
		cv::Size size;
		cv::Point pos;
		mC.locateROI(size, pos);
		ExprTokenType param[2], temp, * params[] = { param,param + 1 };
		param[0].SetValue(size.width), param[1].SetValue(size.height);
		temp = g_ahkapi->Object_New(IAhkApi::ObjectType::Array, params, 2);
		g_ahkapi->VarAssign(v1, temp), temp.object->Release();
		param[0].SetValue(pos.x), param[1].SetValue(pos.y);
		temp = g_ahkapi->Object_New(IAhkApi::ObjectType::Array, params, 2);
		g_ahkapi->VarAssign(v1, temp), temp.object->Release();
		return;
	}
	case M_setTo:
	case M_copyTo:
	case M_convertTo: {
		cv::_OutputArray m;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (aID == M_convertTo) {
			mC.convertTo(m, (int)TokenToInt64(*aParam[1]), aParamCount > 2 ? TokenToDouble(*aParam[2]) : 1.0, aParamCount > 3 ? TokenToDouble(*aParam[3]) : 0.0);
		}
		else {
			cv::_InputArray mask = cv::noArray();
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], mask);
			if (aID == M_setTo)
				mC.setTo(m, mask);
			else
				mC.copyTo(m, mask);
		}
		return;
	}
	case M_assignTo: {
		cv::UMat m;
		if ((__result = TokenToVal(*aParam[0], m)) == CONDITION_TRUE)
			mC.assignTo(m, aParamCount > 1 ? (int)TokenToInt64(*aParam[1]) : -1);
		else
			aResultToken.result = __result;
		return;
	}
	case M_mul:
	case M_dot: {
		cv::_InputArray m;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (aID == M_mul) {
			UMat* mm = (UMat*)sPrototype->New(nullptr, 0);
			mm->mC = mC.mul(m, aParamCount > 1 ? TokenToDouble(*aParam[1]) : 1.0);
			aResultToken.SetValue(mm);
		}
		else aResultToken.SetValue(mC.dot(m));
		return;
	}
	case M_reshape:
	case M_inv:
	case M_t: {
		auto m = (UMat*)sPrototype->New(nullptr, 0);
		if (aID == M_t)
			m->mC = mC.t();
		else if (aID == M_inv)
			m->mC = mC.inv(aParamCount ? (int)TokenToInt64(*aParam[0]) : 0);
		else
			m->mC = mC.reshape((int)TokenToInt64(*aParam[0]), aParamCount > 1 ? (int)TokenToInt64(*aParam[1]) : 0);
		aResultToken.SetValue(m);
		return;
	}
	case M_clone: {
		auto m = (UMat*)sPrototype->New(nullptr, 0);
		m->mC = mC.clone();
		aResultToken.SetValue(m);
		return;
	}
	case M_create: {
		__int64 _rows, _cols, _type;
		if (ParamIndexToVal(0, _rows) || ParamIndexToVal(1, _cols) || ParamIndexToVal(2, _type))
			_o_return_result;
		mC.create((int)_rows, (int)_cols, (int)_type);
		return;
	}
	case M_diag:
	case M_row:
	case M_col:
	case M_rowRange:
	case M_colRange: {
		auto mat = (UMat*)sPrototype->New(nullptr, 0);
		int p1 = (int)TokenToInt64(*aParam[0]);
		int p2 = aParamCount > 1 ? (int)TokenToInt64(*aParam[1]) : 0;
		if (aID == M_rowRange)
			mat->mC = mC.rowRange(p1, p2);
		else if (aID == M_colRange)
			mat->mC = mC.colRange((int)TokenToInt64(*aParam[0]), (int)TokenToInt64(*aParam[1]));
		else if (aID == M_row)
			mat->mC = mC.row((int)TokenToInt64(*aParam[0]));
		else if (aID == M_col)
			mat->mC = mC.col((int)TokenToInt64(*aParam[0]));
		else {
			if (auto obj = TokenToObject(*aParam[0])) {
				if (obj->IsOfType(UMat::sPrototype))
					mat->mC = cv::UMat::diag(((UMat*)obj)->mC);
				else {
					aResultToken.result = g_ahkapi->TypeError(_T("UMat"), *aParam[0]);
					return;
				}
			}
			else
				mat->mC = mC.diag((int)TokenToInt64(*aParam[0]));
		}
		aResultToken.SetValue(mat);
		return;
	}
	case M_step1:
		aResultToken.SetValue((__int64)mC.step1(aParamCount ? (int)TokenToInt64(*aParam[0]) : 0));
		return;
	case M_eye:
	case M_ones:
	case M_zeros: {
		__int64 p1 = 0, p2 = 0, p3 = 0, p4 = 1;
		if (ParamIndexToVal(0, p1) || ParamIndexToVal(1, p2) || ParamIndexToVal(2, p3))
			_o_return_result;
		if (aID == M_ones)
			mC = cv::UMat::ones((int)p1, (int)p2, (int)p3);
		else if (aID == M_zeros)
			mC = cv::UMat::zeros((int)p1, (int)p2, (int)p3);
		else mC = cv::UMat::eye((int)p1, (int)p2, (int)p3);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	}
}


ObjectMember Mat::sMember[] = {
	Object_Method(__New, 0, NA),
	Object_Method(__Delete, 0, 0),
	Object_Method(adjustROI, 4, 4),
	Object_Method(assignTo, 1, 2),
	Object_Method(Call, 1, 1),
	Object_Method(clone, 0, 0),
	Object_Method(col, 1, 1),
	Object_Method(colRange, 2, 2),
	Object_Method(convertTo, 2, 4),
	Object_Method(copyTo, 1, 2),
	Object_Method(create, 3, 3),
	Object_Method(cross, 1, 1),
	Object_Method(diag, 1, 1),
	Object_Method(dot, 1, 1),
	Object_Method(eye, 3, 3),
	Object_Method(getUMat, 1, 2),
	Object_Method(inv, 0, 1),
	Object_Method(locateROI, 2, 2),
	Object_Method(mul, 1, 2),
	Object_Method(ones, 3, 4),
	Object_Method(ptr, 0, 3),
	Object_Method(reshape, 1, 2),
	Object_Method(row, 1, 1),
	Object_Method(rowRange, 2, 2),
	Object_Method(setTo, 1, 2),
	Object_Method(step1, 0, 1),
	Object_Method(t, 0, 0),
	Object_Method(zeros, 3, 3),
	Object_Property_get_set(__Item, 0, 3),
	Object_Property_get(channels),
	Object_Property_get(cols),
	Object_Property_get(depth),
	Object_Property_get(dims),
	Object_Property_get(elemSize),
	Object_Property_get(elemSize1),
	Object_Property_get(empty),
	Object_Property_get(isContinuous),
	Object_Property_get(isSubmatrix),
	Object_Property_get(ptr),
	Object_Property_get(rows),
	Object_Property_get(total),
	Object_Property_get(type),
	Object_Method(add, 1, 1),
	Object_Method(subtract, 1, 1),
	Object_Method(multiply, 1, 1),
	Object_Method(divide, 1, 1),
};

int Mat::sMemberCount = _countof(sMember);

ObjectMember UMat::sMember[] = {
	Object_Method(__New, 0, NA),
	Object_Method(__Delete, 0, 0),
	Object_Method(adjustROI, 4, 4),
	Object_Method(assignTo, 1, 2),
	Object_Method(Call, 1, 1),
	Object_Method(clone, 0, 0),
	Object_Method(col, 1, 1),
	Object_Method(colRange, 2, 2),
	Object_Method(convertTo, 2, 4),
	Object_Method(copyTo, 1, 2),
	Object_Method(create, 3, 3),
	Object_Method(diag, 1, 1),
	Object_Method(dot, 1, 1),
	Object_Method(eye, 3, 3),
	Object_Method(getMat, 1, 1),
	Object_Method(inv, 0, 1),
	Object_Method(locateROI, 2, 2),
	Object_Method(mul, 1, 2),
	Object_Method(ones, 3, 3),
	Object_Method(reshape, 1, 2),
	Object_Method(row, 1, 1),
	Object_Method(rowRange, 2, 2),
	Object_Method(setTo, 1, 2),
	Object_Method(step1, 0, 1),
	Object_Method(t, 0, 0),
	Object_Method(zeros, 3, 3),
	Object_Property_get(channels),
	Object_Property_get(cols),
	Object_Property_get(depth),
	Object_Property_get(dims),
	Object_Property_get(elemSize),
	Object_Property_get(elemSize1),
	Object_Property_get(empty),
	Object_Property_get(isContinuous),
	Object_Property_get(isSubmatrix),
	Object_Property_get(ptr),
	Object_Property_get(rows),
	Object_Property_get(total),
	Object_Property_get(type),
};

int UMat::sMemberCount = _countof(sMember);