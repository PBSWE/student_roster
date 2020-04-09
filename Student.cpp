#include <iostream>
#include "student.h" //Notes from instructor call: "whatever is included in student.h comes with together"
#include <string>
using namespace std;

//Constructor
const string Student::sDegrees[3] = { "SECURITY", "NETWORK", "SOFTWARE" };

Student::Student(string sID, string fName, string lName, string sEmail, int sAge, const int* nDays)
{
    this->sID = sID;
    this->fName = fName;
    this->lName = lName;
    this->sEmail = sEmail;
    this->sAge = sAge;
    this->nDays[0] = nDays[0];
    this->nDays[1] = nDays[1];
    this->nDays[2] = nDays[2];
}
//Accessors (Getters)                   // Notes from instructor call: "write getters, one for each attribute on student.h"
string Student::getsID() const
{
    return sID;
}
string Student::getfName() const
{
    return fName;
}
string Student::getlName() const
{
    return lName;
}
string Student::getsEmail() const
{
    return sEmail;
}
int Student::getsAge() const
{
    return sAge;
}
const int* Student::getnDays() const
{
    return nDays;
}

//Mutators (setters)
void Student::setsID(string para_sID) //Note from instructor call: "avoid using same variable name for your parameters" so using prefix 'para' =)
{
    sID = para_sID;
}
void Student::setfName(string para_fName)
{
    fName = para_fName;
}
void Student::setlName(string para_lName)
{
    lName = para_lName;
}
void Student::setsEmail(string para_sEmail)
{
    sEmail = para_sEmail;
}
void Student::setsAge(int para_sAge)
{
    sAge = para_sAge;
}
void Student::setnDays(const int* para_nDays)
{ // one for each element of the array
    nDays[0] = para_nDays[0];
    nDays[1] = para_nDays[1];
    nDays[2] = para_nDays[2];
}
void Student::setDay1(int fday)
{
    nDays[0] = fday;
}
void Student::setDay2(int secday)
{
    nDays[1] = secday;
}
void Student::setDay3(int thirdday)
{
    nDays[2] = thirdday;
}
string Student::getDegreeProgram() const
{
    return string();
}
void Student::print() const
{
}
Student::~Student() //Destructor                 // Note from instructor call: "the destructor will free the allocated memory used"
{
}
