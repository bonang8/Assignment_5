#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
Student::Student()
{
   id = 1010;
   name = "Yo";
   level = "Unknown";
   major = "Unknown";
   gpa = 0.0;
   advisorField = 0;
}
Student::Student(unsigned int id, string name, string level, string major, double gpa, int advisorField)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->major = major;
  this->gpa = gpa;
  this->advisorField = advisorField;
}
Student::~Student()
{

}
bool Student::operator <(Student& s)
{
  bool itsGreaterThan = true;
  if(this->id < s.id)
  {
    return itsGreaterThan;
  }
  return false;
}
bool Student::operator >(Student& s)
{
  bool itsLessThan = true;
  if(this->id > s.id)
  {
    return itsLessThan;
  }
  return false;
}
bool Student::operator ==(Student& s)
{
  bool itsEqual = true;
  if(this->id == s.id)
  {
    return itsEqual;
  }
  return false;
}
// getters
int Student::getAdvisorField()
{
  return this->advisorField;
}
double Student::getGpa()
{
  return this->gpa;
}
string Student::getMajor()
{
  return this->major;
}
unsigned int Student::getID()
{
  return id;
}
string Student::getName()
{
  return name;
}
string Student::getLevel()
{
  return level;
}
// setters
void Student::setAdvisorField(int advisorField)
{
  this->advisorField = advisorField;
}
void Student::setGpa(double gpa)
{
  this->gpa = gpa;
}
void Student::setMajor(string major)
{
  this->major = major;
}

void Student::setID(unsigned int id)
{
  this->id = id;
}
void Student::setName(string name)
{
  this->name = name;
}
void Student::setLevel(string level)
{
  this->level = level;
}
ostream& operator<<(ostream& os, const Student& s)
{
   os << "id: " << s.id << " name: " << s.name << " level: " << s.level << " major: " << s.major << " gpa: "<< s.gpa<< " advisorField: " << s.advisorField;
   return os;
}
#endif
