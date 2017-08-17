
#include "client.h"

#include "napi.h"

using Napi::ObjectWrap;

namespace node_cec {


class ClientWrapper : public ObjectWrap<ClientWrapper> {
public:
    static void initialize(Napi::Env & env, Napi::Object & target);

    ClientWrapper(Napi::CallbackInfo const & info);

    void initialize_cec(Napi::CallbackInfo const & info);

  private:
    Client client;
};

}
