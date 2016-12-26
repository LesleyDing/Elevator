//Programmer name: Hanzhi Ding
//Programmer's ID: 1466750

#ifndef Rider_H
#define Rider_H

struct Rider
{
  const int from;
  const int to;
  const bool goingUp;
  const bool goingDown;

  Rider(const int, const int);
  Rider& operator=(const Rider&);
};

#endif