//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Panel.h"
#include "Rider.h"
#include "Floor.h"
#include "Building.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Elevator
{
  static const int IDLE = 0; 
  static const int UP = 1;
  static const int DOWN = -1;

  // elevator metrics
  const int speed; // inches per second, up or down
  const unsigned int CAPACITY; 
  int location; // inches above ground level
  int direction; // equal to IDLE, UP, DOWN
  int atFloorIndex; // -1 if door is closed
  int timer;

  vector<Rider> riders;
  
  public:
  Elevator(unsigned int, int, int);
  operator int() const {return location;}

  // count-down timer before closing door
  void resetTimer() {timer = 3;}
  void tickTimer() {timer--;}
  bool timedOut() const {return timer == 0;}

  bool isOpen() const {return atFloorIndex >= 0;}
  void openDoorTo(int); // parameter is index in Building::floors array
  void board(const Rider&); // adds a Rider to the Elevator

  // added in lab 9
  bool hasRiderForFloor() const;
  void removeRider();
  bool isFull() const {return CAPACITY == riders.size();}
  bool goingUp() const {return direction == UP;}
  bool goingDown() const {return direction == DOWN;}
  int getFloorIndex() const {return atFloorIndex;}

  Panel panel;
  
  // friend function
  friend ostream& operator<<(ostream&, const Elevator&); 
};

#endif