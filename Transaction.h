#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include<string>
#include "Student.h"
#include "Faculty.h"
class Transaction{
  public:
    // this will contain the different transactionTypes. '
    // Ex: if the user in main chooses either #s from 7-12, we store it here.
    int transactionType;
    // str indicates that it is a string object to help keep track
    string str_TransactionDescription;
    // keeps track of student id
    // useful if advisor and advisee is modified
    unsigned int idStudent;
    // keeps track of faculty id
    // useful if advisor and advisee is modified
    unsigned int idFaculty;
    Student *ptr_student;
    Faculty *ptr_faculty;

    Transaction()
    {
      transactionType = 0;
      string str_TransactionDescription = "";
      idStudent = 0;
      idFaculty = 0;
      this->ptr_student = NULL;
      this->ptr_faculty = NULL;
    }
    Transaction(int transactionType, Student*ptr_student, Faculty*ptr_faculty, string str_TransactionDescription, unsigned int idStudent, unsigned int idFaculty)
    {
       this->transactionType = transactionType;
       this->ptr_student = ptr_student;
       this->ptr_faculty = ptr_faculty;
       this->str_TransactionDescription = str_TransactionDescription;
       this->idStudent = idStudent;
       this->idFaculty = idFaculty;
    }

   // getters
   int getTransactionType()
   {
     return transactionType;
   }
   unsigned int getFacultyID()
   {
     return idFaculty;
   }
   unsigned int getStudentID()
   {
     return idStudent;
   }
   string getDesciprtion()
   {
     return str_TransactionDescription;
   }
   /*void displayTransaction()
   {
     cout << "transactionType: " << transactionType << ""
   }
   */

   /*
   Student *getStudentPtr()
   {
     return ptr_student;
   }
   */

};
#endif
