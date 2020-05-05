#include "Student.h"
#include "ListNode.h"
#include "Faculty.h"
#include "Tree.h"
#include<iostream>
using namespace std;
unsigned int getNewUniqueStudentID()
{
  static unsigned int nextUniqueStudentID = 0;
  nextUniqueStudentID++;
  return nextUniqueStudentID;
}
int main(int argc, const char * argv[])
{
   cout << "Hello" << endl;

   unsigned int uniqueStudentID = getNewUniqueStudentID();
   cout << "uniqueStudentID: " << uniqueStudentID << endl;
   Student *ptr_S = new Student(uniqueStudentID, "Clarisse", "Junior", "Computer Science", 3.8, 2525);
   uniqueStudentID = getNewUniqueStudentID();
   cout << "uniqueStudentID: " << uniqueStudentID << endl;
   Student *ptr_S2 = new Student(uniqueStudentID, "Mia", "Junior", "Computer Science", 3.8, 2525);
   Faculty *ptr_F = new Faculty(1, "Johnson", "Professor", "Computer Science");
   Faculty *ptr_F2 = new Faculty(2, "Stevens", "Professor", "Computer Science");
   //Faculty *ptr_F3 = new Faculty(3, "Trace", "Professor", "Computer Science");
   cout << "Yo" << endl;
   cout << *ptr_F;
   ptr_F->insertNewAdvisee(ptr_S->id);
   cout << endl;
   cout << "Printing Advisees" << endl;
   ptr_F->printAdvisee();
   ptr_F->insertNewAdvisee(ptr_S2->id);
   cout << "Printing Advisees" << endl;
   ptr_F->printAdvisee();
   cout << endl;

   DoublyLinkedList<int> *ptr_DL = new DoublyLinkedList<int>();
   ptr_DL->insertFront(1);
   ptr_DL->insertFront(2);
   ptr_DL->insertFront(3);
   ptr_DL->insertFront(4);
   ptr_DL->printList();
   ptr_DL->remove(3);
   cout << endl;
   ptr_DL->printList();

   cout << *ptr_S;
   cout << endl;
   cout << *ptr_S2;
   cout << endl;
   // comparing Student
   if(*ptr_S > *ptr_S2)
   {
     cout << "Student_1 is itsGreaterThan Student_2"<< endl;
   }
   else if(*ptr_S == *ptr_S2)
   {
     cout << "Student_1 is equal Student_2"<< endl;
   }
   else
   {
     cout << "Student_2 is itsGreaterThan Student_1"<< endl;
   }
  // comparing Faculty
   if(*ptr_F > *ptr_F2)
   {
     cout << "Faculty_1 is itsGreaterThan Faculty_2"<< endl;
   }
   else if(*ptr_F == *ptr_F2)
   {
     cout << "Faculty_1 is equal Faculty_2"<< endl;
   }
   else
   {
     cout << "Faculty_2 is itsGreaterThan Faculty_1"<< endl;
   }

   delete ptr_S;
   delete ptr_S2;

   // Testing Tree
   //BST *myTree = new BST();
   //myTree->insert(20);
   //myTree->insert(8);
   //myTree->insert(22);
   //myTree->insert(4);
   //myTree->insert(12);

}
