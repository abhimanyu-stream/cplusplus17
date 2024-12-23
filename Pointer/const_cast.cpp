

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void display()
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
    // int localVar = 10;
    // return &localVar; // Returning address of a local variable (dangling pointer)

    const int num = 10;
    int *numPtr = const_cast<int *>(&num);
    *numPtr = 20; // Undefined behavior if `num` was truly const
}
/**
const_cast

Used to add or remove const or volatile qualifiers from a variable.
Does not change the actual const-ness of the object in memory.
*/