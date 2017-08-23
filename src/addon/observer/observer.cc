
#include "observer.h"

namespace node_cec
{
 
void Observer::update(Event & e) {
    e.handle();
}

}
