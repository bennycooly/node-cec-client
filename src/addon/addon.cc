

#include "client.h"
#include "client-wrapper.h"

#include "libcec/cec.h"
#include "libcec/cectypes.h"

#include "napi.h"

#include <iostream>


namespace node_cec
{

void say_hello(Napi::CallbackInfo const & info)
{
    int hello = CEC_DEFAULT_PHYSICAL_ADDRESS;
    std::cout << "Hello " << hello << std::endl;
}


void init(Napi::Env env, Napi::Object exports, Napi::Object module)
{
    exports.Set("hello", Napi::Function::New(env, say_hello, "hello"));

    ClientWrapper::initialize(env, exports);
}



NODE_API_MODULE(cec_client, init);

}
