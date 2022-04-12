#pragma once
#include <ahkapi.h>

struct ObjVTable {
public:
	void* rtti;
	void* vt[14];
};
extern ObjVTable vftable;

// cvahk is same as IAhkApi::Object_New(IAhkApi::ObjectType::Module)
class cvahk : public Object
{
	ULONG STDMETHODCALLTYPE AddRef() { return 0; }
	ULONG STDMETHODCALLTYPE Release() { return 0; }
	STDMETHODIMP QueryInterface(REFIID riid, void** ppv) { return E_NOTIMPL; }
	HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT* pctinfo) { return E_NOTIMPL; }
	HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) { return E_NOTIMPL; }
	HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) { return E_NOTIMPL; }
    HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) {
        return E_NOTIMPL;
    }
	bool Delete() { return false; }
	LPTSTR Type() { return nullptr; }
	Object* Base() { return nullptr; }
	bool IsOfType(Object* aPrototype) { return false; }
	void DebugWriteProperty(IDebugProperties* aDebugger, int aPage, int aPageSize, int aMaxDepth) {}
	
public:
	static Object* Create();
	typedef ResultType(IObject::* ObjInvoke)(IObject_Invoke_PARAMS_DECL);
	ObjInvoke ahk_invoke;
	ResultType Invoke(IObject_Invoke_PARAMS_DECL);
	thread_local static IAhkApi::Prototype* sPrototype;
};
