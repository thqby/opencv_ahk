#include "pch.h"
#include "cvobj.h"
#include "cv_ahk.h"

ObjVTable vftable = { 0 };
thread_local IAhkApi::Prototype* cvahk::sPrototype = nullptr;

ObjectBase::~ObjectBase() {}
Object* cvahk::Create()
{
    auto obj = (cvahk*)sPrototype->New(nullptr, 0);
    if (!vftable.rtti) {
        cvahk myobj;
        auto prtti = *(void***)obj - 1;
        memcpy(&vftable, prtti, sizeof(ObjVTable));
        vftable.invoke = vftable.vt[7];
        // replace IObject::Invoke
        vftable.vt[7] = (*(void***)&myobj)[7];
    }
    *(void**)obj = vftable.vt;
    *(void**)&obj->ahk_invoke = vftable.invoke;
    return obj;
}

ResultType cvahk::Invoke(IObject_Invoke_PARAMS_DECL)
{
    if (aFlags & IT_CALL) {
        ResultToken this_token{};
        if (aName && g_ahkapi->Object_GetProp(this_token, this, aName, true) && this_token.symbol == SYM_OBJECT) {
            return this_token.object->Invoke(aResultToken, IT_CALL, nullptr, this_token, aParam, aParamCount);
        }
    }
    return (this->*ahk_invoke)(aResultToken, aFlags, aName, aThisToken, aParam, aParamCount);
}
