//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#include "Panel.h"
#include "Rider.h"
#include "Building.h"
#include "Elevator.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <cstdlib>

Elevator::Elevator(unsigned int capacity, int speed, int start)
:speed(speed), CAPACITY(capacity), direction(IDLE), timer(0)
{
  for (int i = 0; i < Building::FLOORS; i++)
    panel.addButton(Building::floors[i].label);
  atFloorIndex = -1;
  location = Building::floors[start].elevation;
}

void Elevator::openDoorTo(int f)
{
  panel.clear(Building::floors[f].label); // clear the host elevator's panel button for the referenced floor (so its light goes out)
  atFloorIndex = f; // set atFloorIndex to the referenced floor's index
  location = Building::floors[f].elevation; // set location to the referenced floor's elevation
  resetTimer(); // reset the host elevator's count-down timer
}

void Elevator::board(const Rider& r)
{
  // .push_back the Rider to the host elevator's vector or Riders
  riders.push_back(r);

  // access the label for the Rider's destination floor and press the corresponding button on the panel
  if (!panel.isLit(Building::floors[r.to].label))
    panel.press(Building::floors[r.to].label);
  
  // if the Rider is going up, set the host elevator's direction to up, otherwise set the direction down
  if (r.goingUp)
    direction = UP;
  else if (r.goingDown)
    direction = DOWN;
  else
    direction = IDLE;
  
  resetTimer(); // reset the host elevator's count-down timer
}

bool Elevator::hasRiderForFloor() const
{
  // if the door is not open, return false
  if (!isOpen())
    return false;
  
  for(unsigned int i = 0; i < riders.size(); i++) // traverse the host elevator's vector of riders
    if (riders[i].to == atFloorIndex) // if a rider's destination equals the elevator's current floor
      return true;
  
  return false; //if the end of the traversal loop is reached
}

void Elevator::removeRider()
{
  // traverse the host elevator's vector of riders
  // if a rider's destination (.to member) equals the elevator's current floor (atFloorIndex member)
  for(unsigned int i = 0; i < riders.size(); i++)
    if (riders[i].to == atFloorIndex)
    {
      riders.erase(riders.begin() + i); // erase that rider
      panel.clear(Building::floors[atFloorIndex].label); // clear the host elevator's panel button for the current floor
      resetTimer(); // reset the host elevator's count-down timer
      break; // break from the loop (so that no more riders are erased)
    }
}

ostream& operator<<(ostream& out, const Elevator& elevator) 
{
  out.setf(ios::left);
  out.width(14);
  out << "Elevator at";
  out.unsetf(ios::left);
  out.setf(ios::right);
  out.width(5);
  out << elevator.location;
  out.width(15);
  if(elevator.direction == Elevator::IDLE)
	  out << "IDLE";
  if(elevator.direction == Elevator::UP)
	  out << "going UP";
  if(elevator.direction == Elevator::DOWN)
	  out << "going DOWN";
  out.width(5);
  out << elevator.riders.size() << " riders";
  out.width(16);
  if (elevator.isOpen())
	  out << "door is OPEN|" << elevator.timer << "\t";
  out.unsetf(ios::right);
  out << elevator.panel;
  
  return out;
}