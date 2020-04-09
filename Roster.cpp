#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"

using namespace std;

//Notes from the instructor call: "Always define the empty constructor - it gets called by default if no other specified!""
Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1; //Note from instructor call: "-1 means EMPTY since 0 is a valid index in an array"
    classRosterArray = NULL;
}

Roster::Roster(int capacity) //Setting a max capacity for the Roster
{
    this->capacity = capacity;
    this->lastIndex = -1;
    classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentAt(int index)
{
    return classRosterArray[index];
}

//Calls a separate add() method at the end
void Roster::parseThenAdd(string row)
{
    if (lastIndex < capacity)
    {
        lastIndex++;
        string sID = "";
        int from = 0;
        for (int i = from; i < from + 2; ++i)
        {
            sID += row[i];
        }
        from += 3;
        string fName;
        for (int i = from; row[i] != ',' && i < row.size(); ++i)
        {
            fName += row[i];
            from = i;
        }
        from += 2;
        string lName = "";
        for (int i = from; row[i] != ',' && i < row.size(); ++i)
        {
            lName += row[i];
            from = i;
        }
        from += 2;
        string sEmail = "";
        for (int i = from; row[i] != ',' && i < row.size(); ++i)
        {
            sEmail += row[i];
            from = i;
        }
        from += 2;
        string sAges = "";
        for (int i = from; row[i] != ',' && i < row.size(); ++i)
        {
            sAges += row[i];
            from = i;
        }
        int sAge = stoi(sAges);
        from += 2;
        // Parse Days in course.
        string day1s, day2s, day3s;
        for (int i = from; row[i] != ',' && i < row.size(); ++i)
        {
            day1s += row[i];
            from = i;
        }
        from += 2;
        for (int i = from; row[i] != ',' && i < row.size(); ++i)
        {
            day2s += row[i];
            from = i;
        }
        from += 2;
        for (int i = from; row[i] != ',' && i < row.size(); ++i)
        {
            day3s += row[i];
            from = i;
        }
        int day1 = stoi(day1s);
        int day2 = stoi(day2s);
        int day3 = stoi(day3s);
        from += 2;
        // Parse degree program.
        string degreeStr = "";
        Degree sDegree;
        for (int i = from; i < row.size(); ++i)
        {
            degreeStr += row[i];
            from = i;
        }
        if (degreeStr == Student::sDegrees[0])
            sDegree = SECURITY;
        else if (degreeStr == Student::sDegrees[1])
            sDegree = NETWORK;
        else if (degreeStr == Student::sDegrees[2])
            sDegree = SOFTWARE;
        else
        {
            std::cerr << "Invalid Degree type." << endl;
            exit(1);
        }
        add(sID, fName, lName, sEmail, sAge, day1, day2, day3, sDegree); //The add() method will create the Software, Security or Network degree

    }
    else
    {
        cerr << "ERROR! LIST HAS EXCEEDED MAX CAPACITY \n EXITING NOW!";
        exit(1);
    }
}

// This method creates the degree of proper type, then adds to Roster - all parsed values passed in.
void Roster::add(string sID, string fName, string lName, string sEmail,
    int sAge, int day1, int day2, int day3, Degree sDeg)

{
    Student** temp;
    temp = classRosterArray;
    // ++lastIndex;
    // classRosterArray = new Student *[lastIndex++];
    for (int i = 0; i < lastIndex; ++i)
        classRosterArray[i] = temp[i];
    int days[3] = { day1, day2, day3 };
    if (sDeg == SOFTWARE)
        classRosterArray[lastIndex] = new SoftwareStudent(sID, fName, lName, sEmail, sAge, days, sDeg);
    else if (sDeg == NETWORK)
        classRosterArray[lastIndex] = new NetworkStudent(sID, fName, lName, sEmail, sAge, days, sDeg);
    else
        classRosterArray[lastIndex] = new SecurityStudent(sID, fName, lName, sEmail, sAge, days, sDeg);
}

void Roster::print_all() const //Roll through the array of degrees and call print method for each one
{
    for (int i = 0; i <= lastIndex; i++)
        classRosterArray[i]->print();
}

void Roster::remove(string sID) 
{
    bool removing = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getsID() == sID) //Student found
        {
            removing = true;
            delete this->classRosterArray[i]; //Move last student to this position so there are no gaps in array
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--; // Roster is one element smaller     
        }
    }
    if (removing == false)
        cout << "Student not found!" << endl;
}

void Roster::printAverageDaysInCourse(string sID) const
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getsID() == sID) // Student found
        {
            found = true;
            int sum = classRosterArray[i]->getnDays()[0] + classRosterArray[i]->getnDays()[1] + classRosterArray[i]->getnDays()[2];
            cout << "The average of Student ID " << sID << " is " << (sum / 3.0f) << ".\n";
        }
    }
    if (!found)
        cout << "Student not found \n";
}

void Roster::printInvalidEmails() const // PA note: "a valid email should include an at sign '@' and period '.' and should not include a space"
{
    cout << "Displaying invalid email entries:\n";
    cout << endl;
    string the_email;
    for (int i = 0; i <= lastIndex; i++)
    {
        the_email = classRosterArray[i]->getsEmail();
        bool atfound = false;
        bool dotfound = false;
        for (int j = 0; j < the_email.size(); j++) {
            if (the_email[j] == ' ') {
                cout << the_email << endl;
                atfound = true;
                dotfound = true;
                break;
            }
            if (the_email[j] == '@')
                atfound = true;
            if (the_email[j] == '.')
                dotfound = true;
        }
        if (atfound == false || dotfound == false) {
            cout << the_email << endl;
        }
        // Note from instructor: "use npos or char not found"
        //Old solution for print invalid emails:
        //if ((the_email.find(' ')) || ((!the_email.find('@'))) && ((!the_email.find('.'))))
        //    //classRosterArray[i];
          
    }   
}

void Roster::printByDegreeType(int degree) const
{
    cout << "Printing students of type " << Student::sDegrees[degree] << "\n";
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getDegreeProgram() ==
            Student::sDegrees[degree])
            this->classRosterArray[i]->print();
    }
}

Roster::~Roster() //destroys all the students (like this project is doing to me........)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete classRosterArray[i]; //Deletes each student first
    }
    delete[] classRosterArray; // Deletes the dynamically allocated array of pointers to the students
}

/*
########################################
####### INT MAIN FUNCTION CODE #########
########################################
*/

int main()
{

    cout << "C++ Class Course / C++ / Student ID / Student Name" << endl;

    int numStudent = 5; // Input is 6 long comma-delimited strings
    const string studentData[5] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,FirstNa,LastNa,student@email.com,99,0,0,1,SOFTWARE" };

    Roster* rep = new Roster(numStudent); //Make the Roster
    std::cout << "Parsing data and adding students:\t";
    for (int i = 0; i < numStudent; i++)
    {
        rep->parseThenAdd(studentData[i]); // Parse each line turn them into students, and add them to Roster
    }
    cout << "DONE.\n";
    cout << endl;

    cout << "Displaying all students: \n";
    cout << endl;
    rep->print_all(); // Display all students in the Roster

    cout << "\n" << endl;

    rep->printInvalidEmails();
   
    cout << "\n" << endl;

    cout << "Printing average days for students:\n" << endl;

    rep->printAverageDaysInCourse("A1");
    rep->printAverageDaysInCourse("A2");
    rep->printAverageDaysInCourse("A3");
    rep->printAverageDaysInCourse("A4");
    rep->printAverageDaysInCourse("A5");
    

    cout << "\n" << endl;
    cout << "Printing all Software students:\n" << endl;
    rep->printByDegreeType(SOFTWARE);

    cout << "\n" << endl;

    cout << "Removing A3:"; // Remove student with the supplied ID
    //int remove(const string sID); // Remove function here to return void instead bool .
    cout << "\n" << endl;
    rep->remove("A3");

    rep->print_all();
    numStudent--;
    cout << "\n" << endl;
    cout << "Removing A3:\n"; // Remove student with the supplied ID
    rep->remove("A3"); // student not found. 
  
    cout << "\n" << endl;
    cout << "Have a nice day!" << endl;
    cout << endl;
    rep->~Roster();
    return 0;
}

/*
Notes from instructor calls:
- Roster is the main cpp that will run your program.
- Add the student subjects to roster.
- Return int (do not return void like assessment says).
- Reach out to instructors with any questions (which I did a million times)
*/



/*
// roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
*/
