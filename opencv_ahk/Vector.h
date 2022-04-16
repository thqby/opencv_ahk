#pragma once
#include <ahkapi.h>
#include <vector>
#include "util.h"

class VectorBase : public Object
{
public:
	int mFlags;
	void* mPtr;
	VectorBase* mRoot;
	thread_local static IAhkApi::Prototype* sPrototype;
};

template<typename T> struct is_vector_type { enum { VALUE = 0 }; };
template<typename T> struct is_vector_type<std::vector<T>> { enum { VALUE = 1 }; };

template<typename T>
class Vector : public VectorBase
{
	~Vector() {}
	enum MemBerID {
		M___New,
		M___Delete,
		P_Ptr,
		P_Size,
		P___Item,
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
		case M___Delete: {
			this->~Vector(); mBase = nullptr;
			if (mRoot) {
				mRoot->Release();
				mRoot = nullptr;
			}
			return;
		}
		case M___New: {
			new (&mC) std::vector<T>;
			mFlags = cv::_InputOutputArray(mC).getFlags();
			mPtr = &mC;
			if (aParamCount == 0 || aParam[0] == g_invalid)return;
			if (aParamCount == 1) {
				if (ParamIndexToVal(0, mC))
					_o_return_result;
				return;
			}
			else _o_invalid_param;
		}
		case P_Ptr: return (void)aResultToken.SetValue((__int64)((std::vector<T>*)mPtr)->data());
		case P_Size: {
			if (aFlags & IT_SET) {
				size_t sz;
				if (ParamIndexToVal(0, (__int64&)sz))
					_o_return_result;
				((std::vector<T>*)mPtr)->resize(sz);
				return;
			}
			else
				return (void)aResultToken.SetValue((__int64)((std::vector<T>*)mPtr)->size());
		}
		case P_empty: return (void)aResultToken.SetValue((__int64)((std::vector<T>*)mPtr)->empty());
		case P___Item: {
			auto pvec = (std::vector<T>*)mPtr;
			size_t index;
			if (aFlags & IT_SET) {
				if (ParamIndexToVal(1, (__int64&)index))
					_o_return_result;
				__result = TokenToVal(*aParam[0], (*pvec)[index]);
				if (__result != CONDITION_TRUE)
					_o_return_result;
				return;
			}
			else {
				if (ParamIndexToVal(0, (__int64&)index))
					_o_return_result;
				if (index >= pvec->size())
					return (void)(aResultToken.result = g_ahkapi->Error(_T("invalid index"), nullptr, IAhkApi::ErrorType::Index));
				if (is_vector_type<T>::VALUE) {
					T t{};
					ResultToken result{};
					ValToResult(t, result);
					if (result.symbol == SYM_OBJECT && result.object->IsOfType(VectorBase::sPrototype)) {
						auto vec = ((VectorBase*)result.object);
						vec->mPtr = &(*pvec)[index];
						vec->mRoot = mRoot ? mRoot : this;
						vec->mRoot->AddRef();
						aResultToken.SetValue(vec);
					}
					else {
						g_ahkapi->ResultTokenFree(aResultToken);
						ValToResult((*pvec)[index], aResultToken);
					}
				}
				else
					ValToResult((*pvec)[index], aResultToken);
				return;
			}
		}
		case M_push: {
			T val;
			if (ParamIndexToVal(0, val))
				_o_return_result;
			((std::vector<T>*)mPtr)->push_back(val);
			return;
		}
		case M_pop: return ((std::vector<T>*)mPtr)->pop_back();
		case M_clear: return ((std::vector<T>*)mPtr)->clear();
		case M_toArray: return VectorToResult((*(std::vector<T>*)mPtr), aResultToken, true);
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
	Object_Property_get_set(Size),
	Object_Property_get(empty),
	Object_Property_get_set(__Item, 1, 1),
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


