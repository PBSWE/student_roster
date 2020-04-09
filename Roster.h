#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster
{
public:
    int lastIndex; // Index of last course in roster, also records how many entries in the roster
    int capacity;  // Max Roster size
    Student** classRosterArray;

    Roster();             // Note from instructor call: "empty constructor creates roster & initializes all fields to default values"
    Roster(int capacity); // same as above but sets max size

    Student* getStudentAt(int index);
    void parseThenAdd(string dataarrow); // Note from instructor call: "parseThenAdd parses strings, creates Student objects and adds to the roster"
    void add(
        string sID,
        string fName,
        string lName,
        string sEmail,
        int sAge,
        int, int, int, // 3 intentional ints to allow for the 3 days to complete the course
        Degree sDeg);  // called at the end

    void print_all() const;  //prints all degrees/students in roster using each degree's print() method
    void remove(string sID); // removes a student based on its ID
    void printAverageDaysInCourse(string sID) const;
    void printByDegreeType(int degree) const; // Prints some degree average type.
    void printInvalidEmails() const;

    ~Roster(); // Desctructor destroys the roster, releasing any resources it requested dynamically.
};
#endif