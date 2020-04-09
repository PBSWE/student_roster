#include <iostream>
#include "softwareStudent.h"
#include "degree.h"

SoftwareStudent::SoftwareStudent(
    string sID,
    string fName,
    string lName,
    string sEmail,
    int sAge,
    const int* nDays,
    Degree sDeg)
    : Student(sID, fName, lName, sEmail, sAge, nDays)
{
    sDegree = sDeg;
}

string SoftwareStudent::getDegreeProgram() const
{
    return sDegrees[sDegree];
}

void SoftwareStudent::print() const
{
    std::cout << "Student ID: " << getsID()
        << "\t"
        << "First Name: " << getfName()
        << "\t"
        << "Last Name: " << getlName()
        << "\t"
        << "Age: " << getsAge() << "\t"
        << "\t"
        << "Days in Course: {" << getnDays()[0]
        << ", " << getnDays()[1] << ", " << getnDays()[2] << "}"
        << "\t"
        << "Degree Program: Software" << std::endl;
}

SoftwareStudent::~SoftwareStudent()
{
}
