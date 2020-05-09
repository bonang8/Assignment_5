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
   Faculty *ptr_F = new Faculty(3, "Johnson", "Professor", "Computer Science");
   Faculty *ptr_F2 = new Faculty(4, "Stevens", "Professor", "Computer Science");
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

   //delete ptr_S;
  //  delete ptr_S2;

/*
   // Testing Tree with only ints
   BST<int>*ptr_myTree = new BST<int>();
   ptr_myTree->insert(20);
   ptr_myTree->insert(8);
   ptr_myTree->insert(22);
   ptr_myTree->insert(4);
   ptr_myTree->insert(12);
   ptr_myTree->printTree();
   bool searchForNum = ptr_myTree->search(20);
   if(searchForNum)
   {
     cout << "found 20" << endl;
   }
   else
   {
     cout << "couldn't find 20" << endl;
   }
   searchForNum = ptr_myTree->search(4);
   if(searchForNum)
   {
     cout << "found 4" << endl;
   }
   else
   {
     cout << "couldn't find 4" << endl;
   }
   searchForNum = ptr_myTree->search(100);
   if(searchForNum)
   {
     cout << "found 100" << endl;
   }
   else
   {
     cout << "couldn't find 100" << endl;
   }


   bool deletedNode = ptr_myTree->deleteNode(4);
   if(deletedNode)
   {
     cout << "deleted 4" << endl;
   }
   else
   {
     cout << "couldn't find 4" << endl;
   }

  TreeNode<int>*ptr_TreeNode =  ptr_myTree->getSuccessor(ptr_myTree->root);
  cout << "TreeNode: " << ptr_TreeNode->key<< endl;
  cout << "key: "<< ptr_myTree->root->key << endl;
  ptr_myTree->printTree();

*/
// Testing if Tree with objects work.

  BST<Student>*ptr_studentTree = new BST<Student>();
  BST<Faculty>*ptr_facultyTree = new BST<Faculty>();
  //student
  ptr_studentTree->insert(ptr_S->getID(),ptr_S);
  ptr_studentTree->insert(ptr_S2->getID(), ptr_S2);
  ptr_studentTree->printTree();
  //faculty
  ptr_facultyTree->insert(ptr_F->getID(), ptr_F);
  ptr_facultyTree->insert(ptr_F2->getID(), ptr_F2);
  ptr_facultyTree->printTree();


cout << "=========START OF PROGRAM========="<< endl;
  // The user's choice
  int answer = 0;
  cout << "What action would you like to preform?: " << endl;
  cout << "1: Print all students and their information" << endl;
  cout << "2: Print all faculty and their information" << endl;
  cout << "3: Find and display student information given the students id" << endl;
  cout << "4: Find and display faculty information given the faculty id" << endl;
  cout << "7: Add a new student" << endl;
  cout << "8: Delete a student given the id" << endl;
  cout << "9: Add a new faculty member" << endl;
  cout << "10: Delete a faculty member given the id" << endl; 
  cin >> answer;

  //prints all studenst and their information
  if(answer == 1){
      if(ptr_studentTree->isEmpty()){
        cout << "There are no students currently in the data base." << endl;
        //break;
      }
      else{
         cout << "There is something there" << endl;
         ptr_studentTree->printTreeNodes();
      }
    }

  //prints all faculty and their information
  if(answer == 2){
    if(ptr_facultyTree->isEmpty()){
        cout << "There are no faculty currently in the data base." << endl;
        //break;
      }
      else{
        ptr_facultyTree->printTreeNodes();
      }
  }

 // find and displays student information given the student id
   if(answer == 3)
   {
     unsigned int studentID = 0;
     if(ptr_studentTree->isEmpty()){
       cout << "There are no students currently in the data base." << endl;
       //break;
     }

     cout << "Enter the student ID: ";
     cin >> studentID;
     ptr_studentTree->printTreeNode(studentID);
   }
 // find and display faculty information given the faculty id
   if(answer == 4)
   {
     unsigned int facultyID = 0;
     if(ptr_facultyTree->isEmpty()){
       cout << "There are no faculty currently in the data base." << endl;
       //break;
     }
     cout << "Enter the faculty ID: ";
     cin >> facultyID;
     ptr_facultyTree->printTreeNode(facultyID);
   }



  // To add a new Student
  if(answer == 7){
        unsigned int tempID = 0;
        string tempName = "";
        string tempLevel = "";
        string tempMajor = "";
        double tempGPA = 0;
        int tempAdvisorField  = 0;
        cout << "Please enter the students ID number: " << endl;
        cin >> tempID;
        cout << "Please enter in their name: " << endl;
        cin >> tempName;
        cout << "Please enter their level: " << endl;
        cin >> tempLevel;
        cout << "Please enter in their major: " << endl;
        cin >> tempMajor;
        cout << "Please enter in their advisor field: " << endl;
        cin >> tempAdvisorField;
        Student *ptr_Student = new Student(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorField);
        ptr_studentTree->insert(tempID, ptr_Student);
        cout << "Added Sucessfully" << endl;
      }

  // Delete a student given the id
  if(answer == 8){
    unsigned int studentID = 0;
    cout << "Please enter the ID: " << endl;
    cin >> studentID;
     if(ptr_studentTree->isEmpty())
     {
       cout << "The tree is empty" << endl;
     }
     // if it's not empty, check to make sure that it is in the tree
     // if search is true then
     else if(ptr_studentTree->search(studentID))
     {
       cout << "===Deleting===" << endl;
       ptr_studentTree->printTreeNode(studentID);
       ptr_studentTree->deleteNode(studentID);
       cout << "===Updated student database===" << endl;
       ptr_studentTree->printTree();
     }
     else
     {
       cout << "ID not found in the student database" << endl;
     }
  }

  // Add a new faculty member
  if(answer == 9){
      int tempID = 0;
      string tempName = "";
      string tempLevel = "";
      string tempDepartment = "";
      cout << "Please enter in the ID" << endl;
      cin >> tempID;
      cout << "Please enter in their name: " << endl;
      cin >> tempName;
      cout << "Please enter in their level: " << endl;
      cin >> tempLevel;
      cout << "Please enter the department: " << endl;
      cin >> tempDepartment;
      Faculty *ptr_Faculty = new Faculty(tempID, tempName, tempLevel, tempDepartment);
      ptr_facultyTree->insert(tempID, ptr_Faculty);
      cout << "Sucessfully inserted" << endl;
    }

    //Delete a faculty member given the id.
    if(answer == 10){
      unsigned int facultyID = 0;
      cout << "Please enter the ID: " << endl;
      cin >> facultyID;
       if(ptr_facultyTree->isEmpty())
       {
         cout << "The tree is empty" << endl;
       }
       // if it's not empty, check to make sure that it is in the tree
       // if search is true then
       else if(ptr_facultyTree->search(facultyID))
       {
         cout << "===Deleting===" << endl;
         ptr_facultyTree->printTreeNode(facultyID);
         ptr_facultyTree->deleteNode(facultyID);
         cout << "===Updated student database===" << endl;
         ptr_facultyTree->printTree();
       }
       else
       {
         cout << "ID not found in the faculty database" << endl;
       }
    }



}
