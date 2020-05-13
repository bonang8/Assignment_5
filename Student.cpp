#include "Student.h"
Student::Student()
{
   id = 1010;
   name = "Yo";
   level = "Unknown";
   major = "Unknown";
   gpa = 0.0;
   advisorField = 0;
}
Student::Student(unsigned int id, string name, string level, string major, double gpa, int advisorField)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->major = major;
  this->gpa = gpa;
  this->advisorField = advisorField;
}
Student::~Student()
{

}
bool Student::operator <(Student& s)
{
  bool itsGreaterThan = true;
  if(this->id < s.id)
  {
    return itsGreaterThan;
  }
  return false;
}
bool Student::operator >(Student& s)
{
  bool itsLessThan = true;
  if(this->id > s.id)
  {
    return itsLessThan;
  }
  return false;
}
bool Student::operator ==(Student& s)
{
  bool itsEqual = true;
  if(this->id == s.id)
  {
    return itsEqual;
  }
  return false;
}
// getters
int Student::getAdvisorField()
{
  return this->advisorField;
}
double Student::getGpa()
{
  return this->gpa;
}
string Student::getMajor()
{
  return this->major;
}
unsigned int Student::getID()
{
  return id;
}
string Student::getName()
{
  return name;
}
string Student::getLevel()
{
  return level;
}
// setters
void Student::setAdvisorField(int advisorField)
{
  this->advisorField = advisorField;
}
void Student::setGpa(double gpa)
{
  this->gpa = gpa;
}
void Student::setMajor(string major)
{
  this->major = major;
}

void Student::setID(unsigned int id)
{
  this->id = id;
}
void Student::setName(string name)
{
  this->name = name;
}
void Student::setLevel(string level)
{
  this->level = level;
}
ostream& operator<<(ostream& os, const Student& s)
{
   os << "id: " << s.id << " name: " << s.name << " level: " << s.level << " major: " << s.major << " gpa: "<< s.gpa<< " advisorField: " << s.advisorField;
   return os;
}
string Student::serializeToString(){
  //ofstream myOFile;
  //myOFile.open(fileName,ios_base::app);
  // This function serializes the current object to a string with eacj member delimited by a ','. The string can then be written to a file.
  string str_serialization = to_string(this->id) + "," + this->name + "," + this->level + "," + this->major + "," + to_string(this->gpa) + "," + to_string(this->advisorField) + ",";
  return str_serialization;
}

// Jackson added
void Student::serializeToStringPt2(string fileName){
  ofstream myOFile;
  myOFile.open(fileName,ios_base::app);
  // This function serializes the current object to a string with eacj member delimited by a ','. The string can then be written to a file.
  string str_serialization = to_string(this->id) + "," + this->name + "," + this->level + "," + this->major + "," + to_string(this->gpa) + "," + to_string(this->advisorField) + ",";
  if(myOFile.good()){
    myOFile << str_serialization << endl;
  }
  myOFile.close();
}
Student *Student::deserializeFromString(string str_serialization)
{
  // extract ',' delimited member variable values from string

  cout << str_serialization << endl;
  string substrings[6];// each substring holds the data for one member variable
  string delimiter = ",";
  int i = 0;

  size_t pos = 0;
  string token;
  while ((pos = str_serialization.find(delimiter)) != std::string::npos) {
      token = str_serialization.substr(0, pos);
      cout << token << endl;
      substrings[i] = token;
      str_serialization.erase(0, pos + delimiter.length());
      i++;
  }
   unsigned int tempID = stoi(substrings[0]);
   string tempName = substrings[1];
   string tempLevel = substrings[2];
   string tempMajor = substrings[3];
   double tempGPA = stod(substrings[4]);
   int tempAdvisorField = stoi(substrings[5]);

   Student *ptr_Student = new Student(tempID,tempName,tempLevel,tempMajor, tempGPA, tempAdvisorField);
   return ptr_Student;
}
