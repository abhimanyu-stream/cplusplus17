#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student {
public:

    Student();
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

/**
g++ -c student.cpp -o student.o
g++ -c studentMain.cpp -o main.o
g++ student.o main.o -o program
PS E:\ws-abhimanyu\C++Programs\C++Programming> g++ -c student.cpp -o student.o
PS E:\ws-abhimanyu\C++Programs\C++Programming> g++ -c studentMain.cpp -o main.o
PS E:\ws-abhimanyu\C++Programs\C++Programming> g++ student.o main.o -o program
PS E:\ws-abhimanyu\C++Programs\C++Programming> .\program.exe
These are the Student's information:
Name: Alice | Phone: 9876543210
PS E:\ws-abhimanyu\C++Programs\C++Programming> 

 */