#ifndef FACULTY_H
#define FACULTY_H
#include "Faculty.h"
#include <iostream>
using namespace std;
Faculty::Faculty()
{
  id = 0;
  name = "Unknown";
  level = "LevelUnknown";
  department = "DepartmentUnknown";
  this->ptr_listAdviseesIDs = new DoublyLinkedList<unsigned int>();
}
Faculty::Faculty(unsigned int id, string name, string level, string department)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->department = department;
  this->ptr_listAdviseesIDs = new DoublyLinkedList<unsigned int>();
}
Faculty::~Faculty()
{

}
#if 1
void Faculty::insertNewAdvisee(unsigned int id)
{
  ptr_listAdviseesIDs->insertFront(id);
}
void Faculty::removeAdvisee(unsigned int id)
{
  ptr_listAdviseesIDs->remove(id);
}
void Faculty::printAdvisee()
{
  ptr_listAdviseesIDs->printList();
}
#endif
// getters
unsigned int Faculty::getID()
{
  return id;
}
string Faculty::getName()
{
  return name;
}
string Faculty::getLevel()
{
  return level;
}
string Faculty::getDepartment()
{
  return department;
}
// setters
void Faculty::setID(unsigned int id)
{
  this->id = id;
}
void Faculty::setName(string name)
{
  this->name = name;
}
void Faculty::setLevel(string level)
{
  this->level = level;
}
void Faculty::setDepartment(string department)
{
  this->department = department;
}
// overloading insertion operator
ostream& operator<<(ostream& os, const Faculty& f)
{
   os << "id: " << f.id << " name: " << f.name << " level: " << f.level << " department: " << f.department;
   return os;
}
bool Faculty::operator <(Faculty& f)
{
  bool itsGreaterThan = true;
  if(this->id < f.id)
  {
    return itsGreaterThan;
  }
  return false;
}
bool Faculty::operator >(Faculty& f)
{
  bool itsLessThan = true;
  if(this->id > f.id)
  {
    return itsLessThan;
  }
  return false;
}
bool Faculty::operator ==(Faculty& f)
{
  bool itsEqual = true;
  if(this->id == f.id)
  {
    return itsEqual;
  }
  return false;
}

#endif
