#include <iostream>
#include "Records.h"
//using namespace std;
class Student:public Records
{
  public:
    Student();
    Student(unsigned int id, string name, string level, string major, double gpa, int advisorField);
    ~Student();
   unsigned int id;
   string name;
   string level;
    // contains the student's major
   string major;
   // contains the student's GPA
   double gpa;
   // contains the Faculty ID of the advisor
   int advisorField;
   // compare students with the following operations
   bool operator <(Student& s);
   bool operator >(Student& s);
   bool operator ==(Student& s);
   // getter functions
   int getAdvisorField();
   double getGpa();
   string getMajor();
   // must include from Abstract class records
   unsigned int getID();
   string getName();
   string getLevel();
   // setter functions
   void setAdvisorField(int advisorField);
   void setGpa(double gpa);
   void setMajor(string major);
   // must include from Abstract class records
   void setID(unsigned int id);
   void setName(string name);
   void setLevel(string level);
   friend ostream& operator<<(ostream& os, const Student& s);


};
