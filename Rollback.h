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

           default:
              cout << "Error: unknown transaction type : " << transactionType << endl;



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
