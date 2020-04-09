#ifndef SOFTWARE_STUDENT_H
#define SOFTWARE_STUDENT_H
#include <string>
#include "student.h"

class SoftwareStudent : public Student // Note from instructor call: "SoftwareStudent is a Student subclass, so it inherits from Students class"
{
private:
    Degree sDegree;

public:
    SoftwareStudent(
        string sID,
        string fName,
        string lName,
        string sEmail,
        int sAge,
        const int* nDays,
        Degree sDeg);

    virtual string getDegreeProgram() const;
    virtual void print() const;

    ~SoftwareStudent(); // Destructor
};

#endif