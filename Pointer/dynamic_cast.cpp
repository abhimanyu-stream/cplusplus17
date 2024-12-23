#include <iostream>
using namespace std;

class Base
{
public:
    virtual void display() // virtual function.  In c++ virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class.
                           // Its main purpose is to tell the compiler to perform late binding on the function to achieve run-time polymorphism.
    {
        std::cout << "Base class\n";
    }
};

class Derived : public Base
{
public:
    void display() override
    {
        std::cout << "Derived class\n";
    }
};
int main()
{
    Base *basePtr = new Derived();
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr); // Valid cast
    if (derivedPtr)
    {
        derivedPtr->display(); // Derived class
    }
    else
    {
        std::cout << "Invalid cast\n";
    }

    // My implementation
    Derived d1;
    Base *myBasePtr = &d1;
    myBasePtr->display(); // Derived class
    Base b1;
    b1.display(); // Base class

    return 0;
}
/**
dynamic_cast

Used for safe type casting in an inheritance hierarchy.
Performs a runtime check and returns nullptr if the cast is invalid.
Works only with polymorphic base classes (those with at least one virtual function).
*/