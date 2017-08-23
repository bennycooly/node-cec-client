
#include "client.h"

#include "libcec/cecloader.h"

#include <iostream>
#include <vector>

namespace node_cec
{

Client::Client()
{

}


Client::~Client()
{

}

void Client::initialize()
{
    std::cout << "Initializing CEC Client..." << std::endl;
    configuration = CEC::libcec_configuration{};

    // initialize callbacks
    callbacks = CEC::ICECCallbacks{};
    initialize_callbacks();
    
    configuration.clientVersion = CEC::LIBCEC_VERSION_CURRENT;
    configuration.callbacks = &callbacks;
    
    adapter = std::unique_ptr<CEC::ICECAdapter>{ LibCecInitialise(&configuration) };
    if (!adapter)
    {
        std::cerr << "Adapter is null" << std::endl;
        throw std::exception{ "error in initialization occurred" };
    }

    // adapter->InitVideoStandalone();

    std::string port = get_adapter_port();
    adapter->Open(port.c_str());
}

void Client::destroy()
{
    if (adapter.get() == nullptr)
    {
        return;
    }
    UnloadLibCec(adapter.get());
}

void Client::initialize_callbacks()
{
    callbacks.logMessage = &Client::Callbacks::log_message;
    callbacks.keyPress = &Client::Callbacks::key_press;
    callbacks.commandReceived = &Client::Callbacks::command_received;
    callbacks.configurationChanged = &Client::Callbacks::configuration_changed;
    callbacks.alert = &Client::Callbacks::alert;
    callbacks.menuStateChanged = &Client::Callbacks::menu_state_changed;
    callbacks.sourceActivated = &Client::Callbacks::source_activated;
}


std::string Client::get_adapter_port()
{
    std::cout << "Detecting port for Pulse Eight CEC Adapter..." << std::endl;
    uint8_t max_num_devices = 10;
    // CEC::cec_adapter_descriptor device_list[max_num_devices];
    // std::vector<CEC::cec_adapter_descriptor> device_list{ max_num_devices };
    CEC::cec_adapter_descriptor device_list[10];
    auto num_devices = adapter->DetectAdapters(device_list, max_num_devices);
    if (num_devices == 0)
    {
        throw std::exception{ "no adapter detected" };
    }

    std::cout << "Adapter port found: " << device_list[0].strComName << std::endl;
    return device_list[0].strComName;
}


/* Callbacks */

void Client::Callbacks::log_message(void * cbparam, CEC::cec_log_message const * message)
{
    std::cout << message->message << std::endl;
}

void Client::Callbacks::key_press(void * cbparam, CEC::cec_keypress const * key)
{

}

void Client::Callbacks::command_received(void * cbparam, CEC::cec_command const * command)
{

}

void Client::Callbacks::configuration_changed(void * cbparam, CEC::libcec_configuration const * configuration)
{

}

void Client::Callbacks::alert(void * cbparam, CEC::libcec_alert const alert, CEC::libcec_parameter const param)
{

}

int Client::Callbacks::menu_state_changed(void * cbparam, CEC::cec_menu_state const state)
{
    return state;
}

void Client::Callbacks::source_activated(void * cbParam, CEC::cec_logical_address const logicalAddress, uint8_t const bActivated)
{

}

}
