//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#include "Panel.h"
#include "Rider.h"
#include "Floor.h"
#include "Building.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <climits>

const char* const Floor::UP = "Up";
const char* const Floor::DOWN = "Down";
int Floor::TOP = INT_MIN; // defined in climits
int Floor::BOTTOM = INT_MAX; // also in climits

Floor::Floor(const int elevation, const char* const name, const char* const label)
: name(name), label(label), elevation(elevation)
{
  panel.addButton(UP);
  panel.addButton(DOWN);
  if (TOP < elevation) TOP = elevation;
  if (elevation < BOTTOM) BOTTOM = elevation;
}

bool Floor::hasUpRider() const
{
  return !upRiders.empty();
}
bool Floor::hasDownRider() const
{
  return !downRiders.empty();
}

void Floor::addRider(const Rider& r)
{
  if (r.goingUp)
  {  
    upRiders.push(r);
	if (!panel.isLit(UP))
      panel.press(UP);
  }
  if (r.goingDown)
  {  
    downRiders.push(r);
	if (!panel.isLit(DOWN))
      panel.press(DOWN);
  }
}

Rider Floor::removeUpRider()
{
  // throw an exception if the queue is empty
  if (upRiders.empty()) throw "no up riders!";
  // make a local copy of the rider at the front of the up-rider queue  
  Rider boardedRider = upRiders.front();
  // pop the rider at the front of the up-rider queue
  upRiders.pop();
  // return the local copy
  return boardedRider;
}

Rider Floor::removeDownRider()
{
  // throw an exception if the queue is empty
  if (downRiders.empty()) throw "no down riders!";
  // make a local copy of the rider at the front of the up-rider queue  
  Rider boardedRider = downRiders.front();
  // pop the rider at the front of the up-rider queue
  downRiders.pop();
  // return the local copy
  return boardedRider;
}

ostream& operator<<(ostream& out, const Floor& floor)
{
  out.setf(ios::left);
  out.width(3);
  out << floor.label;
  out.width(12);
  out << floor.name << " at ";
  out.width(3);
  out << floor.elevation << "\" Up/Down: ";
  out.width(2);
  out << floor.upRiders.size() << "/" << floor.downRiders.size();
  cout.width(4);
  out<< " Buttons:";
  if (floor.panel.isLit(Floor::UP))
    out << "[UP]";
  if (floor.panel.isLit(Floor::DOWN))
    out << "[Down]";
  out.unsetf(ios::left);

  return out;
}