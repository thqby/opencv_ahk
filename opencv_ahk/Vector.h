#pragma once
#include <ahkapi.h>
#include <vector>
#include "util.h"

class VectorBase : public Object
{
public:
	int Flags;
	thread_local static IAhkApi::Prototype* sPrototype;
};

template<typename T>
class Vector : public VectorBase
{
	~Vector() {}
	enum MemBerID {
		M___New,
		M___Delete,
		P_Ptr,
		P_Size,
		P_empty,
		M_push,
		M_pop,
		M_clear,
		M_toArray,
	};
public:
	std::vector<T> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
		ResultType __result;
		switch (aID)
		{
		case M___Delete: this->~Vector(); mBase = nullptr; return;
		case M___New: {
			new (&mC) std::vector<T>;
			Flags = cv::_InputOutputArray(mC).getFlags();
			if (aParamCount == 0 || aParam[0] == g_invalid)return;
			if (aParamCount == 1) {
				if (ParamIndexToVal(0, mC))
					_o_return_result;
				return;
			}
			else _o_invalid_param;
		}
		case P_Ptr: return (void)aResultToken.SetValue((__int64)mC.data());
		case P_Size: return (void)aResultToken.SetValue((__int64)mC.size());
		case P_empty: return (void)aResultToken.SetValue((__int64)mC.empty());
		case M_push: {
			T val;
			if (ParamIndexToVal(0, val))
				_o_return_result;
			mC.push_back(val);
			return;
		}
		case M_pop: return mC.pop_back();
		case M_clear: return mC.clear();
		case M_toArray: return ValToResult(mC, aResultToken);
		default:
			break;
		}
	}
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

template<typename T>
thread_local IAhkApi::Prototype* Vector<T>::sPrototype = nullptr;

template<typename T>
ObjectMember Vector<T>::sMember[] = {
	Object_Method(__New, 0, NA),
	Object_Method(__Delete, 0, 0),
	Object_Property_get(Ptr),
	Object_Property_get(Size),
	Object_Property_get(empty),
	Object_Method(push, 1, 1),
	Object_Method(pop, 0, 0),
	Object_Method(clear, 0, 0),
	Object_Method(toArray, 0, 0),
};

template<typename T>
int Vector<T>::sMemberCount = _countof(sMember);

template<typename T, int n>
class Vec : public Object
{
	~Vec() {}
	enum MemBerID {
		M___New,
		M___Delete,
		P_Ptr,
		P_Size,
		M_toArray,
	};
public:
	cv::Vec<T, n> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
		ResultType __result;
		switch (aID)
		{
		case M___Delete: this->~Vec(); mBase = nullptr; return;
		case M___New: {
			new (&mC) cv::Vec<T, n>;
			if (aParamCount == 0 || aParam[0] == g_invalid)return;
			if (aParamCount == 1) {
				if (ParamIndexToVal(0, mC))
					_o_return_result;
				return;
			}
			else _o_invalid_param;
		}
		case P_Ptr: return (void)aResultToken.SetValue((__int64)mC.val);
		case P_Size: return (void)aResultToken.SetValue((__int64)n);
		case M_toArray: return ValToResult(mC, aResultToken);
		default:
			break;
		}
	}
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

template<typename T, int n>
thread_local IAhkApi::Prototype* Vec<T, n>::sPrototype = nullptr;

template<typename T, int n>
ObjectMember Vec<T, n>::sMember[] = {
	Object_Method(__New, 0, NA),
	Object_Method(__Delete, 0, 0),
	Object_Property_get(Ptr),
	Object_Property_get(Size),
	Object_Method(toArray, 0, 0),
};

template<typename T, int n>
int Vec<T, n>::sMemberCount = _countof(sMember);


