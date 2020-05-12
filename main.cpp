#include "Student.h"
#include "ListNode.h"
#include "Faculty.h"
#include "Tree.h"
#include "Rollback.h"
#include "Transaction.h"
#include<iostream>
#include<string>
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
   Student *ptr_S = new Student(uniqueStudentID, "Clarisse", "Junior", "Computer Science", 3.8, 4);
   uniqueStudentID = getNewUniqueStudentID();
   cout << "uniqueStudentID: " << uniqueStudentID << endl;
   Student *ptr_S2 = new Student(uniqueStudentID, "Mia", "Junior", "Computer Science", 3.8, 3);
   uniqueStudentID = getNewUniqueStudentID();
   Student *ptr_S3 = new Student(uniqueStudentID, "Jack", "Freshmen", "Computer Science", 3.8, 3);
   uniqueStudentID = getNewUniqueStudentID();
   Student *ptr_S4 = new Student(uniqueStudentID, "Zoey", "Senior", "Computer Science", 3.8, 4);
   Faculty *ptr_F = new Faculty(3, "Johnson", "Professor", "Computer Science");
   Faculty *ptr_F2 = new Faculty(4, "Stevens", "Professor", "Computer Science");
   Faculty *ptr_F3 = new Faculty(5, "Groot", "Professor", "Computer Science");


   #if 1 // test serializaion code, temporary
   string studentSerializeToString = ptr_S->serializeToString();
   Student *ptr_sTest = Student::deserializeFromString(studentSerializeToString);
   ptr_F2->insertNewAdvisee(ptr_S4->id);
   ptr_F2->insertNewAdvisee(ptr_S->id);
   ptr_F->insertNewAdvisee(ptr_S2->id);
   ptr_F->insertNewAdvisee(ptr_S3->id);
   string facultySerializeToString = ptr_F2->serializeToString();
   Faculty *ptr_fTest = Faculty::deserializeFromString(facultySerializeToString);
   #endif// end of test code
   //Faculty *ptr_F3 = new Faculty(3, "Trace", "Professor", "Computer Science");
   cout << "Yo" << endl;
   cout << *ptr_F;
   //ptr_F->insertNewAdvisee(ptr_S3->id);
   cout << endl;
   cout << "Printing Advisees" << endl;
   ptr_F->printAdvisee();
   //ptr_F->insertNewAdvisee(ptr_S4->id);
   cout << "Printing Advisees" << endl;
   ptr_F->printAdvisee();
   cout << endl;
   #if 0
   ptr_F2->insertNewAdvisee(ptr_S->id);
   ptr_F2->printAdvisee();
   ptr_F->insertNewAdvisee(ptr_S2->id);
   ptr_F2->printAdvisee();
   ptr_F2->insertNewAdvisee(ptr_S4->id);
   #endif




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


// setter - used in do while loop
 bool setter = true;
// Testing if Tree with objects work.
  BST<Student>*ptr_studentTree = new BST<Student>();
  BST<Faculty>*ptr_facultyTree = new BST<Faculty>();
  // will be used for option 13
  //Transaction*ptr_transaction = new Transaction();
  Rollback*ptr_rollback = new Rollback(ptr_studentTree, ptr_facultyTree);

  //student
  ptr_studentTree->insert(ptr_S->getID(),ptr_S);
  ptr_studentTree->insert(ptr_S2->getID(), ptr_S2);
  ptr_studentTree->insert(ptr_S3->getID(), ptr_S3);
  ptr_studentTree->insert(ptr_S4->getID(), ptr_S4);
  ptr_studentTree->printTree();
  //faculty
  ptr_facultyTree->insert(ptr_F->getID(), ptr_F);
  ptr_facultyTree->insert(ptr_F2->getID(), ptr_F2);
  ptr_facultyTree->insert(ptr_F3->getID(), ptr_F3);
  ptr_facultyTree->printTree();

do{
      cout << "=========START OF PROGRAM========="<< endl;
        // The user's choice
        int answer = 0;
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
        cout << "10: Delete a faculty member given the id" << endl;
        cout << "11: Change a student’s advisor given the student id and the new faculty id " << endl;
        cout << "12. Remove an advisee from a faculty member given the ids" << endl;
        cout << "13. Rollback" << endl;
        cout << "14. Exit" << endl;
        cin >> answer;

        //prints all studenst and their information
        if(answer == 1){
            if(ptr_studentTree->isEmpty()){
              cout << "There are no students currently in the data base." << endl;

            }
            else{
               cout << "Student in database" << endl;
               ptr_studentTree->printTreeNodes();
            }
          }

        //prints all faculty and their information
        if(answer == 2){
          if(ptr_facultyTree->isEmpty()){
              cout << "There are no faculty currently in the data base." << endl;
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
         if(answer == 5)
         {
           int tempID = 0;
           if(ptr_studentTree->isEmpty()){
             cout << "There are no students currently in the data base." << endl;
           }
           else{
             cout << "Please enter the ID: " << endl;
             cin >> tempID;
             if(ptr_studentTree->search(tempID)){
                int advisorID = ptr_studentTree->get(tempID)->getAdvisorField();
                ptr_facultyTree->printTreeNode(advisorID);
              }
              else
              {
                cout << "Student not in database" << endl;
              }
           }
         }

         //Given a faculty id, print ALL the names and info of his/her advisees
         if(answer == 6){
           unsigned int facultyTempID = -1;
           unsigned int studentTempID = -1;
           if(ptr_facultyTree->isEmpty()){
             cout << "The faculty database is empty" << endl;
           }
           else{
             cout << "Please enter the ID of the faculty member: " << endl;
             cin >> facultyTempID;
               // from the faculty tree, we access the faculty given the id.
               // From there, we are able to access the size of the linked lists and iterate the correct number of times
               // Then, call getNodeIDAtPos() to return each Student ID in Faculty list.
               // Given the studentID, use printNode to print the student's information
              if(!(ptr_facultyTree->get(facultyTempID)->isAdviseeListEmpty()))
                 {
                    for(int i = 0; i < ptr_facultyTree->get(facultyTempID)->adviseeListSize(); ++i ){

                     studentTempID = ptr_facultyTree->get(facultyTempID)->getAdviseeIDAtPos(i);
                     ptr_studentTree->printTreeNode(studentTempID);
                  }

                }
              else
                {
                      cout << "===Advisee List is empty for faculty id: "<< facultyTempID << endl;
                }
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
              // if the id that the user inputted already exist, then generate a new id for the student
              if(ptr_studentTree->search(tempID))
              {
                unsigned int newTempID = 0;
                newTempID = ptr_studentTree->generateID();
                tempID = newTempID;
                cout << "generated valid ID#: " << tempID << endl;
              }
              cout << "Please enter in their name: " << endl;
              cin >> tempName;
              cout << "Please enter their level: " << endl;
              cin >> tempLevel;
              cout << "Please enter in their major: " << endl;
              cin >> tempMajor;
              cout << "Please enter in their advisor field: " << endl;
              cin >> tempAdvisorField;
              Student *ptr_Student = new Student(tempID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorField);
              cout << "Inserting student record into student database" << endl;
              ptr_studentTree->insert(tempID, ptr_Student);
              cout << "Inserting student into faculty list of advisees" << endl;
              ptr_facultyTree->get(tempAdvisorField)->insertNewAdvisee(tempID);
              cout << "Added Sucessfully" << endl;
              // store this in transaction
              string str_id = to_string(tempID);
              string transactionDescription = "Add StudentID " + str_id;
              Transaction*ptr_transaction = new Transaction(7, ptr_Student, NULL, transactionDescription,tempID,0);
              ptr_rollback->addTransaction(*ptr_transaction);
            }

        // Delete a student given the id
        if(answer == 8){
          unsigned int studentID = 0;
          cout << "Please enter the Student ID: " << endl;
          cin >> studentID;
           if(ptr_studentTree->isEmpty())
           {
             cout << "The tree is empty" << endl;
           }
           // if it's not empty, check to make sure that it is in the tree
           // if search is true then
           else if(ptr_studentTree->search(studentID))
           {
             int facultyID = 0;
             facultyID = ptr_studentTree->get(studentID)->advisorField;
             cout << "===Deleting===" << endl;
             ptr_studentTree->printTreeNode(studentID);
             // RECENTLY ADDED
             // ===In case the user wants to rollback, add to Transaction===
             string str_id = to_string(studentID);
             string transactionDescription = "Delete StudentID " + str_id;
             string tempName = ptr_studentTree->get(studentID)->name;
             string tempLevel = ptr_studentTree->get(studentID)->level;
             string tempMajor = ptr_studentTree->get(studentID)->major;
             double tempGPA = ptr_studentTree->get(studentID)->gpa;
             int tempAdvisorField = ptr_studentTree->get(studentID)->advisorField;
             Student *ptr_Student = new Student(studentID, tempName, tempLevel, tempMajor, tempGPA, tempAdvisorField);
             Transaction*ptr_transaction = new Transaction(8, ptr_Student, NULL, transactionDescription, studentID,tempAdvisorField);
             ptr_rollback->addTransaction(*ptr_transaction);
             // ====end of Transaction====
             ptr_studentTree->deleteNode(studentID);
             cout << "===Updated student database===" << endl;
             ptr_studentTree->printTree();
             // check to see if the student was assigned a faculty advisor
             // if so, remove from list and print updated version
             if(ptr_facultyTree->get(facultyID)->search(studentID)){
               cout << "===Updating Faculty Advisee List===" << endl;
               ptr_facultyTree->get(facultyID)->removeAdvisee(studentID);
               cout << "===Updated faculty List===" << endl;
               ptr_facultyTree->get(facultyID)->printAdvisee();
           }
             cout << "Task Completed" << endl;
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
            if(ptr_facultyTree->search(tempID))
            {
              unsigned int newTempID = 0;
              newTempID = ptr_facultyTree->generateID();
              tempID = newTempID;
              cout << "generated valid ID#: " << tempID << endl;
            }
            cout << "Please enter in their name: " << endl;
            cin >> tempName;
            cout << "Please enter in their level: " << endl;
            cin >> tempLevel;
            cout << "Please enter the department: " << endl;
            cin >> tempDepartment;
            Faculty *ptr_Faculty = new Faculty(tempID, tempName, tempLevel, tempDepartment);
            ptr_facultyTree->insert(tempID, ptr_Faculty);
            cout << "Sucessfully inserted" << endl;
            string str_id = to_string(tempID);
            string transactionDescription = "Add FacultyID " + str_id;
            Transaction*ptr_transaction = new Transaction(9, NULL, ptr_Faculty, transactionDescription,0,tempID);
            ptr_rollback->addTransaction(*ptr_transaction);
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
               unsigned int studentID = 0;
               // check if advisee list is empty
               if(!(ptr_facultyTree->get(facultyID)->isAdviseeListEmpty())){
                   // The code below updates students
                   cout << "Updating Students to remove Advisor" << endl;
                   for(int i = 0; i < ptr_facultyTree->get(facultyID)->adviseeListSize(); ++i ){
                      studentID = ptr_facultyTree->get(facultyID)->getAdviseeIDAtPos(i);
                      cout << "StudentID: "; //<< studentID << endl;
                      ptr_studentTree->get(studentID)->advisorField = -1;
                      cout << "===Updated Students to delete faculty advisor===" << endl;
                      ptr_studentTree->printTreeNode(studentID);
                   }
               }
               cout << "===Deleting Faculty===" << endl;
               ptr_facultyTree->printTreeNode(facultyID);
               ptr_facultyTree->deleteNode(facultyID);
               cout << "===Updated faculty database===" << endl;
               ptr_facultyTree->printTree();
              cout << "Task Completed" << endl;
             }
             else
             {
               cout << "ID not found in the faculty database" << endl;
             }
          }

          //Change a student’s advisor given the student id and the new faculty id.
             if(answer == 11){
               unsigned int tempStuID = 0;
               unsigned int tempFacID = 0;
               unsigned int oldFacID = 0;
               if(ptr_studentTree->isEmpty()){
                 cout << "The student data base is empty" << endl;
               }
               else{
                 if(ptr_facultyTree->isEmpty()){
                   cout << "The faculty database is empty" << endl;
                 }
                 else{
                   cout << "Please enter the Student's ID: " << endl;
                   cin >> tempStuID;
                   cout << "Please enter the new Faculty's ID: " << endl;
                   cin >> tempFacID;
                   // check if faculty ID is in the tree
                   if(ptr_facultyTree->search(tempFacID)){
                         cout << "Assigning: " << ptr_studentTree->get(tempStuID)->getName();
                         cout << " to: " << ptr_facultyTree->get(tempFacID)->getName() << endl;
                         // delete student from the old advisor's list of advisees
                         cout << "===Delete student from the old advisor's list of advisees===" << endl;
                         oldFacID = ptr_studentTree->get(tempStuID)->advisorField;
                         cout << "Old advisor: " << oldFacID << endl;
                         ptr_facultyTree->printTreeNode(oldFacID);
                         // Check if the student exists in the old faculty's list of advisees
                         if(ptr_facultyTree->get(oldFacID)->search(tempStuID)){
                             ptr_facultyTree->get(oldFacID)->removeAdvisee(tempStuID);
                             cout << "===New list for old faculty advisor===" << endl;
                             if(!(ptr_facultyTree->get(oldFacID)->isAdviseeListEmpty())){
                              ptr_facultyTree->get(oldFacID)->printAdvisee();
                             }
                         }
                         else
                         {
                           cout << "Error: advisee was not assigned to old faculty ID | need a program check" << endl;
                         }
                         // reassign the advisorField to the new faculty id
                         ptr_studentTree->get(tempStuID)->advisorField = tempFacID;
                         // insert this into the new advisee list
                         ptr_facultyTree->get(tempFacID)->insertNewAdvisee(tempStuID);
                         cout << "===Updated student with new Advisee==="<< endl;
                         ptr_studentTree->printTreeNode(tempStuID);
                         cout << "===Sucessfully Assigned===" << endl;
                    }
                    else
                    {
                      cout << "New Faculty ID does not exists in the database" << endl;
                    }
                 }
               }
             }


          //Remove an advisee from a faculty member given the ids
            if(answer == 12){
              unsigned int tempStuID = -1;
              unsigned int tempFacID = -1;
              if(ptr_studentTree->isEmpty() || ptr_facultyTree->isEmpty()){
                cout << "One of the databases is empty" << endl;
              }
              else{
                cout << "Please enter the ID of the faculty member: " << endl;
                cin >> tempFacID;
                cout << "Please enter in the student ID: " << endl;
                cin >> tempStuID;
                // check is student and faculty exists in data base
                if(ptr_facultyTree->search(tempFacID) && ptr_studentTree->search(tempStuID)){
                    // check if student exists in faculty's lists of advisees
                    if(ptr_facultyTree->get(tempFacID)->search(tempStuID))
                    {
                      // remove advisee from faculty
                      ptr_facultyTree->get(tempFacID)->removeAdvisee(tempStuID);
                      // update Student to currently not have an advisee
                      ptr_studentTree->get(tempStuID)->advisorField = -1;
                    }
                 }
                 else
                 {
                   cout << "==Student or FacultyID does not exists in database==" << endl;
                 }
              }
            }

            if(answer == 13)
            {
              cout << "Rollback "<< endl;
              ptr_rollback->rollback();

            }

            if(answer == 14){
              exit(0);
            }

    }while(setter);
}
