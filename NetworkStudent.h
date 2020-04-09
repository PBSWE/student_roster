#ifndef NETWORK_STUDENT_H
#define NETWORK_STUDENT_H

#include <string>
#include "student.h"
#include "degree.h"

class NetworkStudent : public Student // A NetworkStudent is a particular type of student, so it inherits from Student class.
{
private:
    Degree sDegree;

public:
    NetworkStudent(
        string sID,
        string fName,
        string lName,
        string sEmail,
        int sAge,
        const int*,
        Degree sDeg);

    virtual string getDegreeProgram() const;
    void print() const;

    virtual ~NetworkStudent(); //Destructor
};

#endif