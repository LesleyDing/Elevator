//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#ifndef Panel_h
#define Panel_h

#include <vector>
#include <string>
#include <ostream>
using namespace std;

class Panel
{
  struct Button
  {
    static int count;
    string label;
    bool isLit;
    int sequence;
  };
public:
  vector<Button> buttons;
  void addButton(string);
  void press(string); 
  void clear(string);
  string getFirstLit() const;
  bool isLit(string) const;
  bool areAnyLit() const;
  friend ostream& operator<<(ostream&, const Panel&);
};

#endif