#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <fstream>
#include <string>
#include"Records.h"
#include "ListNode.h"
using namespace std;
class Faculty:public Records
{
  public:
    Faculty();
    Faculty(unsigned int id, string name, string level, string department);
    ~Faculty();
    unsigned int id;
    string name;
    string level;
    string department;
    // list of integers corresponding to all the faculty member's advises's ids
    DoublyLinkedList<unsigned int> *ptr_listAdviseesIDs;
    // create functions to perform on linked lists
    void insertNewAdvisee(unsigned int id);
    void removeAdvisee(unsigned int id);
    void printAdvisee();
    // getters
    unsigned int getID();
    string getName();
    string getLevel();
    string getDepartment();
    // setters
    void setID(unsigned int id);
    void setName(string name);
    void setLevel(string level);
    void setDepartment(string department);
    friend ostream& operator<<(ostream& os, const Faculty& s);
    bool operator <(Faculty& f);
    bool operator >(Faculty& f);
    bool operator ==(Faculty& f);
    bool search(unsigned int adviseeID);
    unsigned int getAdviseeIDAtPos(int pos);
    bool isAdviseeListEmpty();
    int adviseeListSize();
    // this is th serialize
    string serializeToString();
    static Faculty *deserializeFromString(string str_serialization);
    //Jackson added 
    void serializeToStringPt2(string fileName);
};
#endif
