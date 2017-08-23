
#include "observable.h"

namespace node_cec
{

void Observable::add_observer(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Observable::notify(Event & e) {
    for (auto observer : observers) {
        observer->update(e);
    }
}


}
