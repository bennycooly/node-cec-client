#pragma once

#include "client.h"

#include "napi.h"

namespace node_cec {


class ClientWrapper : public Napi::ObjectWrap<ClientWrapper> {
public:
    /**
     * Initialize the napi module.
     * @param env the napi environment
     * @param target the napi target
     */
    static void initialize(Napi::Env & env, Napi::Object & target);

    ClientWrapper(Napi::CallbackInfo const & info);

    void initialize_cec(Napi::CallbackInfo const & info);

    void add_emitter(Napi::CallbackInfo const & info);

    void test_emit(Napi::CallbackInfo const & info);

  private:
    // libcec client
    Client client;

    // event emitter
    // Napi::Object emitter;
    // Napi::Function emit;
    Napi::ObjectReference emitter;
    Napi::FunctionReference emit;
};

}
