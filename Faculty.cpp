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
// checks if the advisee is in the linked lists
bool Faculty::search(unsigned int adviseeID)
{
  return ptr_listAdviseesIDs->search(adviseeID);
}

unsigned int Faculty::getAdviseeIDAtPos(int pos)
{
  return (ptr_listAdviseesIDs->positionAt(pos));
}

bool Faculty::isAdviseeListEmpty()
{
  return (ptr_listAdviseesIDs->isEmpty());
}

int Faculty::adviseeListSize()
{
  return (ptr_listAdviseesIDs->getSize());
}
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

string Faculty::serializeToString()
{
  string str_serialization = to_string(this->id) + "," + this->name + "," + this->level + "," +  this->getDepartment();

  if(!(ptr_listAdviseesIDs->isEmpty()))
  {
    int sizeOfList = ptr_listAdviseesIDs->getSize();
    for( int i = 0; i < sizeOfList; ++i)
    {
      str_serialization += ",";
      unsigned int idAdvisee = ptr_listAdviseesIDs->positionAt(i);
      str_serialization += to_string(idAdvisee);
    }
  }
   str_serialization += ",";
   return str_serialization;
}

Faculty *Faculty::deserializeFromString(string str_serialization)
{
  // extract ',' delimited member variable values from string

  cout << str_serialization << endl;
  string substrings[4];// each substring holds the data for one member variable
  //any Professor who has 100 advisees would be dead...
  // This array size is bigger than any reasonable number of advisees
  int adviseesIDs[100];
  string delimiter = ",";
  int i = 0;
  int adviseeIndex = 0;
  size_t pos = 0;
  string token;
  while ((pos = str_serialization.find(delimiter)) != std::string::npos) {
      token = str_serialization.substr(0, pos);
      cout << token << endl;
      if(i < 4)
      {
        substrings[i] = token;
      }
      else
      {
         adviseesIDs[adviseeIndex] = stoi(token);
         adviseeIndex++;
      }
      str_serialization.erase(0, pos + delimiter.length());
      i++;
  }
  unsigned tempID = stoi(substrings[0]);
  string tempName = substrings[1];
  string tempLevel = substrings[2];
  string tempDepartment = substrings[3];
  Faculty *ptr_Faculty = new Faculty(tempID,tempName,tempLevel,tempDepartment);
  for(int j = 0; j < adviseeIndex; ++j)
  {
    ptr_Faculty->insertNewAdvisee(adviseesIDs[j]);
  }

  return ptr_Faculty;
}
