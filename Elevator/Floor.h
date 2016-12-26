//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <queue>
#include <iostream>
using namespace std;

#include "Panel.h"
#include "Rider.h"

class Floor
{
  queue<Rider> upRiders, downRiders;
  
  public:
  Floor(const int, const char* const, const char* const); // elevation (inches above ground) of floor, name and label
  operator int() const {return elevation;}
  
  static const char* const UP;
  static const char* const DOWN;
  static int TOP, BOTTOM;
  
  Panel panel;
  const string name; // name of floor, for example: Mezzanine
  const string label; // as it appears on the button panel
  const int elevation; // inches above ground level

  bool hasUpRider() const;
  bool hasDownRider() const;
  void addRider(const Rider&);

  // for external reporting
  friend ostream& operator<<(ostream&, const Floor&); // say name, location, #'s of up/down riders waiting
};
#endif