#include "networkStudent.h"
#include <iostream>

NetworkStudent::NetworkStudent(
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

string NetworkStudent::getDegreeProgram() const
{
    return sDegrees[sDegree];
}

void NetworkStudent::print() const
{
    std::cout << "Student ID: " << getsID()
        << "\t"
        << "First Name: "
        << getfName() << "\t"
        << "Last Name: "
        << getlName() << "\t"
        << "Age: " << getsAge()
        << "\t"
        << "\t"
        << "Days in Course: {" << getnDays()[0]
        << ", " << getnDays()[1] << ", " << getnDays()[2] << "}";
    std::cout << "\t"
        << "Degree Program: Networking" << std::endl;
}

NetworkStudent::~NetworkStudent()
{
}
