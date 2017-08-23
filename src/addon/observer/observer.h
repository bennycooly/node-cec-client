#pragma once

#include "event.h"

namespace node_cec {

class Observer
{
  public:
    virtual void update(Event & e);
};


}

