#pragma once

#include "libcec/cec.h"
#include "libcec/cectypes.h"

#include <memory>
#include <string>

namespace node_cec
{

class Client
{
public:
    Client();
    ~Client();

    void initialize();
    void destroy();

    void initialize_callbacks();

    void handle_command();



    class Callbacks
    {
    public:

        static void log_message(void * cbparam, CEC::cec_log_message const * message);
        static void key_press(void * cbparam, CEC::cec_keypress const * key);
        static void command_received(void * cbparam, CEC::cec_command const * command);
        static void configuration_changed(void * cbparam, CEC::libcec_configuration const * configuration);
        static void alert(void * cbparam, CEC::libcec_alert const alert, CEC::libcec_parameter const param);
        static int menu_state_changed(void * cbparam, CEC::cec_menu_state const state);
        static void source_activated(void * cbParam, CEC::cec_logical_address const logicalAddress, uint8_t const bActivated);
    };

private:
    // pointer to the libcec adapter
    std::unique_ptr<CEC::ICECAdapter> adapter;

    // callbacks
    CEC::ICECCallbacks callbacks;

    // libcec configuration
    CEC::libcec_configuration configuration;

    std::string get_adapter_port();
};

}
