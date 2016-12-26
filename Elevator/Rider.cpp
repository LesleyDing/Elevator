//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#include "Rider.h"
#include "Building.h"

Rider::Rider(const int f, const int t)
: from(f), to(t),
  goingUp(Building::floors[from] < Building::floors[to] ? true : false),
  goingDown(Building::floors[to] < Building::floors[from] ? true : false)
{
}

// Rider's assignment operator overload
Rider& Rider::operator=(const Rider& copyThis) {
    Rider& host = *this; // a reference to the host object
    // detect if the objects are the same or not
    if (this != &copyThis) {
      const_cast<int&>(host.from) = copyThis.from;
      const_cast<int&>(host.to) = copyThis.to;
      const_cast<bool&>(host.goingUp) = copyThis.goingUp;
      const_cast<bool&>(host.goingDown) = copyThis.goingDown;
    }
    return host; // return a "self-reference"
}
