#pragma once

#include <string>
#include <vector>
#include <functional>

namespace node_cec
{

class Event
{
public:
    Event(std::string const & name);

    virtual std::string get_name() = 0;

    virtual void handle() = 0;


    // class Args
    // {
    // public:
    //     template <typename T>
    //     virtual T get_arg() = 0;
    // };

protected:
    // name of the event
    std::string name;

    // callback function
    std::function<void(void)> callback;


};

}