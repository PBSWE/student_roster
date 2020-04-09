#ifndef DEGREE_H
#define DEGREE_H
#include <string>    // including string and namespace here
using namespace std; // so I don't have to add std::string to sDeg
enum Degree
{
    SECURITY,
    NETWORK,
    SOFTWARE
};
// Note from instructor call: "Use the enum as an index, so if you add sDeg[SOFTWARE], it yields string 'SOFTWARE' and so on" cool!

#endif