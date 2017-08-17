
#include "client-wrapper.h"

namespace node_cec {

void ClientWrapper::initialize(Napi::Env & env, Napi::Object & target) {
    Napi::Function constructor = DefineClass(env, "Client",
    {
        InstanceMethod("initialize", &initialize_cec)
    }
    );
    target.Set("Client", constructor);
}

ClientWrapper::ClientWrapper(Napi::CallbackInfo const & info) : Napi::ObjectWrap<ClientWrapper>{ info } {
    client = Client{};
}

void ClientWrapper::initialize_cec(Napi::CallbackInfo const & info) {
    client.initialize();
}



}
