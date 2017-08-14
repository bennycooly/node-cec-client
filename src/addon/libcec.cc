
#include "napi.h"

#include "cec.h"
#include "cectypes.h"

using Napi::Env;
using Napi::Value;
using Napi::Object;
using Napi::Function;
using Napi::CallbackInfo;

namespace cec
{

void say_hello(CallbackInfo const &info)
{

    // napi_value result;
    // napi_create_number(env, 0, &result);
    // return result;
    int hello = CEC_DEFAULT_PHYSICAL_ADDRESS;
    printf("Hello\n%d", hello);
}

void init(Env env, Object exports, Object module)
{
    exports["hello"] = Function::New(env, say_hello, "hello");
    // napi_status status;

    // napi_value fn;
    // status = napi_create_function(env, "hello", SayHello{}(), NULL, &fn);
    // if (status != napi_ok)
    // {
    //     return;
    // }

    // status = napi_set_named_property(env, exports, "hello", fn);
    // if (status != napi_ok)
    // {
    //     return;
    // }
}

NODE_API_MODULE(libcec, init)

} // namespace demo
