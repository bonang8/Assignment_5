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
  int answer = 0;
  int answer = 0;
  BST<Student> *stuTree = new BST<Student>();
  BST<Student> *facTree = new BST<Student>();
  while(answer != 14){
    cout << "What action would you like to preform?: " << endl;
    cout << "1: Print all students and their information" << endl;
    cout << "2: Print all faculty and their information" << endl;
    cout << "3: Find and display student information given the students id" << endl;
    cout << "4: Find and display faculty information given the faculty id" << endl;
    cout << "5: Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6: Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7: Add a new student" << endl;
    cout << "8: Delete a student given the id" << endl;
    cout << "9: Add a new faculty member" << endl;
    cout << "10: Delete a faculty member given the id." << endl;
    cout << "11: Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12: Remove an advisee from a faculty member given the ids" << endl;
    cout << "13: Rollback" << endl;
    cout << "14: Exit" << endl;
    cin >> answer;
    if(answer == 1){
      if(stuTree->isEmpty()){
        cout << "There are no students currently in the data base." << endl;
        break;
      }else{
        stuTree>print();
      }
    }
    if(answer == 2){
      if(facTree->isEmpty()){
        cout << "There are no faculty currently in the data base." << endl;
        break;
      }else{
        facTree>print();
      }
    }
    if(answer == 3){
      if(stuTree->isEmpty()){
        cout << "There are no students currently in the data base." << endl;
        break;
      }else{
        cout << "Please enter id: " << endl;
        cin >> tempID;
        stuTree->get(tempID);
      }
    }
    if(answer == 4){
      if(facTree->isEmpty()){
        cout << "There are no faculty currently in the data base." << endl;
        break;
      }else{
        cout << "Please enter id: " << endl;
        cin >> tempID;
        stuTree->get(tempID);
      }
    }
    if(answer == 5){
      if(stuTree->isEmpty()){
        cout << "There are no students currently in the data base." << endl;
        break;
      }else{
        cout << "Please enter the ID: " << endl;
        cin >> tempID;
        if(stuTree->search(tempID)){
//Need to look at with Clarrise
        cout << facTree->get((stuTree->get(tempID))->getAdvisorField())->print() << endl;
      }else{
        cout << "There is no match for a student with that ID" << endl;
      }
      }
    }
    if(answer == 6){
      if(facTree->isEmpty()){
        cout << "There are no faculty in the data base" << endl;
      }else{
        cout << "Enter the ID: " << endl;
        cin >> tempID;
        cout << facTree->get(tempID)->printAdvisee() << endl;
      }
    }
    if(answer == 7){
      string tempName;
      string tempLevel;
      string tempMajor;
      double tempGPA;
      int tempAdvisorField;
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
      stuTree->insert(new Student(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorField));
      cout << "Added Sucessfully" << endl;
    }
    if(answer == 8){
      if(stuTree->isEmpty()){
        cout << "The student data base is empty" << endl;
      }
      else{
        cout << "Please enter the ID: " <<endl;
        cin >> tempID;
        stuTree->deleteNode(tempID);
      }
    }
    if(answer == 9){
      string tempName;
      string tempLevel;
      string tempDepartment;
      cout << "Please enter in the ID" << endl;
      cin >> tempID;
      cout << "Please enter in their name: " << endl;
      cin >> tempName;
      cout << "Please enter in their level: " << endl;
      cin >> tempLevel;
      cout << "Please enter the department: " << endl;
      cin >> tempDepartment;
      facTree->insert(new Faculty(tempID, tempName, tempLevel, tempDepartment));
      cout << "Sucessfully inserted" << endl;
    }
    if(answer == 10){
      if(facTree->isEmpty()){
        cout << "The faculty data base is empty" << endl;
        break;
      }else{
        cout << "Please enter an ID: " << endl;
        cin >> tempID;
        facTree->deleteNode(tempID);
        cout << "Sucessfully deleted" << endl;
      }
    }
//Need to finish
    if(answer == 11){
      if(stuTree->isEmpty()){
        cout << "The student data base is empty" << endl;
        break;
      }else{
        int tempStuID;
        int tempFacID;
        cout << "Please enter in the students ID: " << endl;
        cin >> tempStuID;
        cout << "Please enter in the faculty's ID: " << endl;
        cin >> tempFacID;
        (facTree->get(stuTree->get(tempStuID)->advisorField))->removeAdvisee(tempStuID);
        stuTree->get(tempStuID)->advisorField->(facTree->get(tempFacID);
        facTree->get(tempFacID)->ptr_listAdviseesIDs->insertFront(stuTree->get(tempStuID));
        cout << "Sucessfully switched advisors" << endl;
      }
    }
//Need to Finish
  if(answer == 12){

    }
//Need to Finish
  if(answer == 13){
    while(!stuTree->isEmpty()){

    }
  if(answer == 14){
    cout << "Have a nice day" << endl;
    exit(0);
  }
  }
}
