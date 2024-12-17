#ifndef COLLEGE_H
#define COLLEGE_H

#include <string>
#include <iostream>
using namespace std;

class College
{
public:
    College();
    // Constructor
    College(const string &name, long long phone);

    // Destructor
    ~College();

    // Display student information
    void showColleges() const;

private:
    string name;
    long long phone;
};

#endif