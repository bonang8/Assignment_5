#ifndef ROLLBACK_H
#define ROLLBACK_H
#include<iostream>
#include "Tree.h"
#include "Transaction.h"
#include "Student.h"
#include "Faculty.h"
class Rollback
{
  public:
    DoublyLinkedList<Transaction> *ptr_transactionList;
    BST<Student>*ptr_studentTree;
    BST<Faculty>*ptr_facultyTree;

    Rollback()
    {
      ptr_transactionList = new DoublyLinkedList<Transaction> ();
      ptr_studentTree = NULL;
      ptr_facultyTree = NULL;
    }
    Rollback(BST<Student>*ptr_studentTree, BST<Faculty>*ptr_facultyTree)
    {
      this->ptr_studentTree = ptr_studentTree;
      this->ptr_facultyTree = ptr_facultyTree;
      ptr_transactionList = new DoublyLinkedList<Transaction>();
    }


    bool rollback()
    {
       // check if its not empty
       if(!(ptr_transactionList->isEmpty())){
         // get most recent transaction type. Ex: user entered 7, the object's data stored is in there
         Transaction transaction = ptr_transactionList->removeFront();
         // need to get the transaction type that the user entered (7-12)
         int transactionType = transaction.getTransactionType();

         switch(transactionType)
         {
           // rollback to add Student
           case 7:
              rollbackAddStudent(transaction);
              break;
           case 8:
              rollbackDeleteStudent(transaction);
              break;
           case 9:
              rollbackAddFaculty(transaction);
              break;
           case 10:
              rollbackDeleteFaculty(transaction);
              break;
           case 11:
              rollbackChangeStudentAdvisor(transaction);
              break;
           case 12:
              rollbackRemovesFacultyAdvisee(transaction);
              break;
           default:
              cout << "Error: unknown transaction type : " << transactionType << endl;
              break;
         }

     }
     else
     {
       cout << "No transaction to rollback: List of transactions empty" << endl;
     }
    }

    bool rollbackAddStudent(Transaction transaction)
    {
       unsigned int studentID = transaction.getStudentID();
       string str_transactionDesciprtion = transaction.getDesciprtion();
       cout << "Rolling back: " << str_transactionDesciprtion << endl;
       // 1. from roll back, we need to update the tree by performing inverse
       // operations
       // 2. In this case, user added a student and wishes to rollback.
       // So, delete the obj currently added to the list
       ptr_studentTree->deleteNode(studentID);
       return true;
    }
    bool rollbackDeleteStudent(Transaction transaction)
    {
       unsigned int facultyID = transaction.getFacultyID();
       unsigned int studentID = transaction.getStudentID();
       //Student *ptr_student = transaction.getStudentPtr();
       // 1. from roll back, we need to update the tree by performing inverse
       // operations
       // 2. In this case, user deleted a student and wishes to rollback.
       // so insert the student back into the student tree
       // given the correct faculty id, insert the student back by using the function
       //insertNewAdvisee
       ptr_studentTree->insert(studentID, transaction.ptr_student);
       ptr_facultyTree->get(facultyID)->insertNewAdvisee(studentID);
       cout << "rollbackDeleteStudent(): " << " studentID: " << studentID << " facultyID: " << facultyID << endl;
       cout << "Advisees: " << endl;
       ptr_facultyTree->get(facultyID)->printAdvisee();
       return true;
    }
    // This will add faculty to the lists
    bool rollbackAddFaculty(Transaction transaction)
    {
       unsigned int facultyID = transaction.getFacultyID();
       string str_transactionDesciprtion = transaction.getDesciprtion();
       cout << "Rolling back: " << str_transactionDesciprtion << endl;
       // 1. from roll back, we need to update the tree by performing inverse
       // operations
       // 2. In this case, user added a student and wishes to rollback.
       // So, delete the obj currently added to the list
       ptr_facultyTree->deleteNode(facultyID);
       return true;
    }
    bool rollbackDeleteFaculty(Transaction transaction)
    {
      unsigned int facultyID = transaction.getFacultyID();
      unsigned int adviseeID = 0;
      //unsigned int studentID = transaction.getStudentID();
      // 1. from roll back, we need to update the tree by performing inverse
      // operations
      // 2. In this case, user deleted a faculty and wishes to rollback.
      // so insert the faculty back into the faculty tree
      ptr_facultyTree->insert(facultyID, transaction.ptr_faculty);

      // get length of list of advisees
      // iterate over each element using a for loop and the getAdviseeIDAtPos
      // search for student in tree by adviseeID
      // recover student object
      // set advisor of student object to faculty ID.
      for(int i = 0; i < transaction.ptr_faculty->adviseeListSize(); i++)
      {
         adviseeID = transaction.ptr_faculty->getAdviseeIDAtPos(i);
         if(ptr_studentTree->search(adviseeID))
         {
           ptr_studentTree->get(adviseeID)->advisorField = facultyID;
         }
      }
      cout << "rollbackDeleteFaculty(): " << " facultyID: " << facultyID << endl;
      cout << "Advisees: " << endl;
      ptr_facultyTree->get(facultyID)->printAdvisee();
      return true;
    }
    bool rollbackChangeStudentAdvisor(Transaction transaction)
    {
       // set student advisor to previous faculty ID value
       // insert student ID into advisor list of previous faculty
       // remove studentID from advisee list of reassigned faculty advisor
       ptr_studentTree->get(transaction.idStudent)->advisorField = transaction.getFacultyPrevious();
       ptr_facultyTree->get(transaction.getFacultyPrevious())->insertNewAdvisee(transaction.idStudent);
       ptr_facultyTree->get(transaction.idFaculty)->removeAdvisee(transaction.idStudent);
       cout << "rollbackChangeStudentAdvisor() " << " reassigning studentID: " << transaction.idStudent << " from newFacultyID: " << transaction.idFaculty << " back to oldFacultyID: " << transaction.getFacultyPrevious() << endl;
       return true;
    }
    bool rollbackRemovesFacultyAdvisee(Transaction transaction)
    {
      // set student advisee's advisor field to facultyID
      // insert student advisee(given the student ID) back into Faculty
      ptr_studentTree->get(transaction.idStudent)->advisorField = transaction.idFaculty;
      ptr_facultyTree->get(transaction.idFaculty)->insertNewAdvisee(transaction.idStudent);
      cout << "rollbackRemovesFacultyAdvisee: " << " facultyID: " << transaction.idFaculty <<  " and newly inserted studentID: " << transaction.idStudent << endl;
      cout << "Advisees: " << endl;
      ptr_facultyTree->get(transaction.idFaculty)->printAdvisee();
      return true;
    }
    void addTransaction(Transaction transaction)
    {
      cout << "adding transaction: type: "<< transaction.getTransactionType()
      << ";" << transaction.getDesciprtion().c_str() << endl;

      // add to transaction to list
      ptr_transactionList->insertFront(transaction);
      // should delete the most oldest transaction from the back of the list but its not essential for this project
    }

};
#endif
