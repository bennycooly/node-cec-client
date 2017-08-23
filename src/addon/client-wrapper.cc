
#include "client-wrapper.h"

#include <iostream>

namespace node_cec {

void ClientWrapper::initialize(Napi::Env & env, Napi::Object & target) {
    Napi::Function constructor = DefineClass(env, "Client",
    {
        InstanceMethod("initialize", &initialize_cec),
        InstanceMethod("addEmitter", &add_emitter),
        InstanceMethod("testEmit", &test_emit)
    }
    );
    target.Set("Client", constructor);
}

ClientWrapper::ClientWrapper(Napi::CallbackInfo const & info):
    Napi::ObjectWrap<ClientWrapper>{ info },
    client{}
{
    
}

void ClientWrapper::initialize_cec(Napi::CallbackInfo const & info)
{
    std::cout << info[0].As<Napi::Function>() << std::endl;
    client.initialize();
}

void ClientWrapper::add_emitter(Napi::CallbackInfo const & info)
{
    std::cout << info.This().Type() << std::endl;
    // emitter = info[0].As<Napi::Object>();
    // emitter_ref = Napi::ObjectReference::New(emitter);
    // emit = emitter_ref.Get("emit").As<Napi::Function>();
    emitter = Napi::Persistent(info[0].As<Napi::Object>());
    emit = Napi::Persistent(emitter.Get("emit").As<Napi::Function>());
    emit.Call(emitter.Value(), {Napi::String::New(info.Env(), "initializing")});
}

void ClientWrapper::test_emit(Napi::CallbackInfo const & info) {
    std::cout << "in native test_emit" << std::endl;
    // emit = emitter_ref.Get("emit").As<Napi::Function>();
    emit.Call(emitter.Value(), {Napi::String::New(info.Env(), "test emit")});
}

}
