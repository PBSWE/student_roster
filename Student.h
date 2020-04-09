#ifndef STUDEND_H
#define STUDEND_H
#include <string>
#include "degree.h"
using namespace std;

class Student
{

protected:
    string sID;    // Student ID
    string fName;  // First Name
    string lName;  // Last Name
    string sEmail; // Student Email
    int sAge;      // Student Age
    int nDays[3];  // Number of Days to course completion (Array of size 3)

    //Constructor
public:
    static const string sDegrees[3];
    Student(string sID, string fName, string lName, string sEmail, int sAge, const int* nDays);
    const static int nDaysArraySize = 3;

    //Accessors (getters)
    string getsID() const;
    string getfName() const;
    string getlName() const;
    string getsEmail() const;
    int getsAge() const;
    const int* getnDays() const;

    //Mutators (setters)
    void setsID(string sID);
    void setfName(string fName);
    void setlName(string lName);
    void setsEmail(string sEmail);
    void setsAge(int sAge);
    void setnDays(const int* nDay);
    void setDay1(int);
    void setDay2(int);
    void setDay3(int);

    virtual string getDegreeProgram() const;
    virtual void print() const;

    //The destructor
    virtual ~Student();
};

#endif