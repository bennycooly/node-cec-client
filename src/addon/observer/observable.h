#pragma once

#include "observer.h"
#include "event.h"

#include <vector>
#include <memory>

namespace node_cec
{

class Observable
{
public:
    virtual void add_observer(std::shared_ptr<Observer> observer);

    virtual void notify(Event & e);

protected:
    std::vector<std::shared_ptr<Observer>> observers;

};

}