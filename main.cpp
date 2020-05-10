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
  bool setter = true;
  BST<Faculty> *ptr_facultyTree = new BST<Faculty>();
  BST<Student> *ptr_studentTree = new BST<Student>();
   unsigned int uniqueStudentID = getNewUniqueStudentID();
   cout << "uniqueStudentID: " << uniqueStudentID << endl;
   Student *ptr_S = new Student(uniqueStudentID, "Clarisse", "Junior", "Computer Science", 3.8, 2525);
   uniqueStudentID = getNewUniqueStudentID();
   cout << "uniqueStudentID: " << uniqueStudentID << endl;
   Student *ptr_S2 = new Student(uniqueStudentID, "Mia", "Junior", "Computer Science", 3.8, 2525);
   Faculty *ptr_F = new Faculty(3, "Johnson", "Professor", "Computer Science");
   Faculty *ptr_F2 = new Faculty(4, "Stevens", "Professor", "Computer Science");


do{
cout << "=========START OF PROGRAM========="<< endl;
  // The user's choice
  int answer = 0;
  cout << "What action would you like to preform?: " << endl;
  cout << "1: Print all students and their information" << endl;
  cout << "2: Print all faculty and their information" << endl;
  cout << "3: Find and display student information given the students id" << endl;
  cout << "4: Find and display faculty information given the faculty id" << endl;
  cout << "5: Given a student’s id, print the name and info of their faculty advisor." << endl;
  cout << "6: Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << "7: Add a new student" << endl;
  cout << "8: Delete a student given the id" << endl;
  cout << "9: Add a new faculty member" << endl;
  cout << "10: Delete a faculty member given the id" << endl;
  cout << "11: Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12: Remove an advisee from a faculty member given the ids" << endl;
  cout << "14: Exit program" << endl;
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
   //Given a student’s id, print the name and info of their faculty advisor
   if(answer == 5){
     int tempID = -1;
     if(ptr_studentTree->isEmpty()){
       cout << "Student database is empty" << endl;
     }else{
       cout << "Please enter the ID of the student: " << endl;
       cin >> tempID;
       cout << ptr_facultyTree->get(ptr_studentTree->get(tempID)->advisorField) << endl;
     }
   }
   //Given a faculty id, print ALL the names and info of his/her advisees
   if(answer == 6){
     int tempID = -1;
     if(ptr_facultyTree->isEmpty()){
       cout << "The faculty data base is empty" << endl;
     }else{
       cout << "Please enter in the faculty's ID: " << endl;
       cin >> tempID;
     }
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
    //Change a student’s advisor given the student id and the new faculty id.
    if(answer == 11){
      int tempStuID = -1;
      int tempFacID = -1;
      if(ptr_studentTree->isEmpty()){
        cout << "The student data base is empty" << endl;
      }else{
        if(ptr_facultyTree->isEmpty()){
          cout << "The faculty database is empty" << endl;
        }
        else{
          cout << "Please enter the Student's ID: " << endl;
          cin >> tempStuID;
          cout << "Please enter the Faculty's ID: " << endl;
          cin >> tempFacID;
          cout << "Assigning: " << ptr_studentTree->get(tempStuID);
          cout << "to: " << ptr_facultyTree->get(tempFacID) << endl;
          ptr_studentTree->get(tempStuID)->advisorField = tempFacID;
          ptr_facultyTree->get(tempFacID)->ptr_listAdviseesIDs->insertFront(tempStuID);
          cout << "===Sucessfully Assigned===" << endl;
        }
      }
    }
    //Remove an advisee from a faculty member given the ids
    if(answer == 12){
      int tempStuID = -1;
      int tempFacID = -1;
      if(ptr_studentTree->isEmpty() || ptr_facultyTree->isEmpty()){
        cout << "One of the databases is empty" << endl;
      }else{
        cout << "Please enter the ID of the faculty member: " << endl;
        cin >> tempFacID;
        cout << "Please enter in the student ID: " << endl;
        cin >> tempStuID;
        if(ptr_facultyTree->get(tempFacID)->ptr_listAdviseesIDs->search(tempStuID)){
          ptr_facultyTree->get(tempFacID)->ptr_listAdviseesIDs->remove(tempStuID);
          ptr_studentTree->get(tempStuID)->advisorField = -1;
        }
      }
    }
    if(answer == 14){
      exit(0);
    }
  }while(setter);


}
