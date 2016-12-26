#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <cstdlib>
#include <ctime>

#include "Rider.h"
#include "Building.h"
#include "Floor.h"
#include "Panel.h"

int main( )
{
  srand(time(0)); rand(); // initialize the random number generator

  // Seed elevator 0 with riders who should dembark
  for (int i = 0; i < 3; i++)
    Building::elevators[1].board(Rider(4, 0));
 
  for (int i = 0;; i++) // an infinite counting loop
  { 
    cout << "-----------------------------------------------\n";
    cout << "-- Time " << i << " ---------------------------\n";
    for (int elevator = 0; elevator < Building::ELEVATORS; elevator++)
      cout << Building::elevators[elevator] << endl;

    for (int floor = 0; floor < Building::FLOORS; floor++)
      cout << Building::floors[floor] << endl;

    Building::action(5.0); // add an average of 5 riders per second
 
    cout << "Press ENTER to continue... ";
    cin.get();
  }
}