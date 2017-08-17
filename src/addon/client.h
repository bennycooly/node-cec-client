#pragma once

#include "libcec/cec.h"
#include "libcec/cectypes.h"

namespace node_cec {

class Client
{
  public:
    Client();
    ~Client();

    void initialize();

  private:
    CEC::ICECAdapter* adapter;
    CEC::ICECCallbacks callbacks;
    CEC::libcec_configuration configuration;
};

}
