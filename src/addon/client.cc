
#include "client.h"

#include "libcec/cecloader.h"

#include <iostream>

namespace node_cec {

Client::Client() {
    
}

Client::~Client() {
    UnloadLibCec(adapter);
}

void Client::initialize() {
    std::cout << "Initializing CEC Client" << std::endl;
    callbacks = CEC::ICECCallbacks{};
    configuration = CEC::libcec_configuration{};
    configuration.clientVersion = CEC::LIBCEC_VERSION_CURRENT;

    adapter = LibCecInitialise(&configuration);
}

}
