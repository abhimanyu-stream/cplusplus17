#include "College.h"

College::College() {}
// Constructor implementation
College::College(const string &name, long long phone) : name(name), phone(phone) {}

// Destructor implementation
College::~College() {}
// Function to display student details
void College::showColleges() const
{
    cout << "These are the Student's information:" << endl;
    cout << "Name: " << name << " | Phone: " << phone << endl;
}