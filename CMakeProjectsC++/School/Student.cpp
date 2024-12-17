#include "Student.h"

Student::Student() {}

// Constructor implementation
Student::Student(const string &name, long long phone) : name(name), phone(phone) {}

// Destructor implementation
Student::~Student() {}
// Function to display student details
void Student::showStudents() const
{
    cout << "These are the Student's information:" << endl;
    cout << "Name: " << name << " | Phone: " << phone << endl;
}
/**
Here’s an example of how to create a header file in C++ and use it in a class implementation.

Steps to Create and Use a Header File
Create a Header File (Student.h):

Define the class and its members in the header file.
Use include guards or #pragma once to prevent multiple inclusions.
Create a Source File (Student.cpp):

Implement the member functions of the class in this file.
Include the header file.
Create a Main File (main.cpp):

Include the header file.
Use the class.
1. Header File (Student.h)
cpp
Copy code
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student {
public:
    // Constructor
    Student(const string& name, long long phone);

    // Destructor
    ~Student();

    // Display student information
    void showStudents() const;

private:
    string name;
    long long phone;
};

#endif // STUDENT_H
2. Source File (Student.cpp)
cpp
Copy code
#include "Student.h"

// Constructor implementation
Student::Student(const string& name, long long phone) : name(name), phone(phone) {}

// Destructor implementation
Student::~Student() {}

// Function to display student details
void Student::showStudents() const {
    cout << "These are the Student's information:" << endl;
    cout << "Name: " << name << " | Phone: " << phone << endl;
}
3. Main File (main.cpp)
cpp
Copy code
#include "Student.h"

int main() {
    Student student1("Alice", 9876543210);  // Create object using parameterized constructor
    student1.showStudents();               // Display student information

    return 0;
}
Explanation of the Example
Header File (Student.h):

Contains the declaration of the Student class, including its constructor, destructor, and member functions.
The include guard (#ifndef, #define, and #endif) ensures the header file is not included multiple times during compilation.
Source File (Student.cpp):

Contains the implementation of the Student class functions.
Includes the Student.h header to define the class.
Main File (main.cpp):

Includes the Student.h header to use the Student class.
Demonstrates object creation and usage.
Compilation and Execution
To compile and run this code, use the following commands:

Compile
bash
Copy code
g++ -c Student.cpp -o Student.o
g++ -c main.cpp -o main.o
g++ Student.o main.o -o program
Run
bash
Copy code
./program
This modular approach separates declarations and implementations, making the codebase easier to manage and reuse in larger projects.
 */