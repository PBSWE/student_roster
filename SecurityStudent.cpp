#include "securityStudent.h"
#include <iostream>
SecurityStudent::SecurityStudent(
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

string SecurityStudent::getDegreeProgram() const
{
	return sDegrees[sDegree];
}

void SecurityStudent::print() const
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
		<< ", " << getnDays()[1] << ", " << getnDays()[2] << "}";
	std::cout << "\t"
		<< "Degree Program: Security" << std::endl;
}

SecurityStudent::~SecurityStudent()
{
}
