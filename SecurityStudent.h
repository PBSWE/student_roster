#ifndef SECURITY_STUDENT_H
#define SECURITY_STUDENT_H
#include <string>
#include "student.h"
#include "degree.h"
class SecurityStudent : public Student // A SecurityStudent is a particular type of student, so it inherits from Student class.
{
private:
    Degree sDegree;

public:
    SecurityStudent(
        string sID,
        string fName,
        string lName,
        string sEmail,
        int sAge,
        const int* nDays,
        Degree sDeg);

    virtual string getDegreeProgram() const;
    void print() const;

    ~SecurityStudent(); // Destructor
};

#endif