/** VirtualFunctionPolymorphism.cpp  
 * Compiled with: g++ -std=c++17 -O3 -o VirtualFunctionPolymorphism.exe VirtualFunctionPolymorphism.cpp
 * Platform: VS Code IDE, Windows 11, MinGW64 GCC Toolchain
 */

#ifndef USER
#define USER

#include <iostream>
#include <string>

using namespace std;

// Base class
class Animal {
public:
    string name;
    string foodHabit;

    // Default constructor
    Animal() {}

    // Virtual function for runtime polymorphism
    virtual void showDetails() {
        cout << "Base class implementation" << endl;
    }

    // Virtual destructor to ensure proper cleanup
    virtual ~Animal() {}
};

// Derived class
class Elephant : public Animal {
public:
    // Constructor to initialize name and foodHabit
    Elephant(std::string, std::string){
        this->name = name;
        this->foodHabit = foodHabit;
    }
   

    // Overriding the virtual function
    void showDetails() override {
        cout << "Child class Elephant implementation" << endl;
        cout << "Name: " << name << ", Food Habit: " << foodHabit << endl;
    }
};

// Main function
int main() {
    cout << "Run-time polymorphism using virtual functions" << endl;

    // Pointer to base class
    Animal* ptrAnimal;

    // Creating an instance of the derived class
    Elephant* elephant1 = new Elephant("Elephant", "Vegetables");

    // Assigning the address of the derived class object to the base class pointer
    ptrAnimal = elephant1;

    // Calling the virtual function
    ptrAnimal->showDetails();

    // Cleaning up dynamically allocated memory
    delete elephant1;

    return 0;
}

#endif
