// Records is an abstract class that holds
// all the necessary function and variable instances to be inherited from
// the Student and Faculty class
#ifndef RECORDS_H
#define RECORDS_H
#include <iostream>
using namespace std;
class Records
{
public:
  virtual unsigned int getID() = 0;
  virtual string getName() = 0;
  virtual string getLevel() = 0;
  virtual void setID(unsigned int id) = 0;
  virtual void setName(string name) = 0;
  virtual void setLevel(string level) = 0;

};
#endif
