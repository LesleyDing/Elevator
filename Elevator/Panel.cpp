//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "Panel.h"

int Panel::Button::count = 0;
void Panel::addButton(string str)
{
  Button b;
  b.label = str;
  b.isLit = false;
  buttons.push_back(b);
}

void Panel::press(string str)
{
  for (unsigned int i = 0; i < buttons.size( ); i++)
    if (str == buttons[i].label)
    {
      buttons[i].isLit = true;
      buttons[i].sequence = Button::count;
      Button::count++;
    }
}

void Panel::clear(string str)
{
  for (unsigned int i = 0; i < buttons.size( ); i++)
    if (str == buttons[i].label)
      buttons[i].isLit = false;
}

string Panel::getFirstLit() const
{
  int tracker = -1;
  for (unsigned int i = 0; i < buttons.size( ); i++)
    if (buttons[i].isLit)
    {
      if(tracker == -1)
        tracker = i;
      if (tracker != -1)
        if (buttons[i].sequence < buttons[tracker].sequence)
          tracker = i;
	}
  
  return buttons[tracker].label;
}

bool Panel::isLit(string str) const
{
  for (unsigned int i = 0; i < buttons.size(); i++) 
    if (str == buttons[i].label) 
      return buttons[i].isLit;

  return false;
}

bool Panel::areAnyLit() const
{
  for (unsigned int i = 0; i < buttons.size(); i++) 
    if (buttons[i].isLit) 
      return buttons[i].isLit;

  return false;
}

ostream& operator<<(ostream& out, const Panel& Panel)
{
  for (unsigned int i = 0; i < Panel.buttons.size(); i++) 
    if (Panel.buttons[i].isLit) 
      out << "[" << Panel.buttons[i].label << "]";

  return out;
}