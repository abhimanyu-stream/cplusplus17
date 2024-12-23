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

    int num = 65;
    char *charPtr = reinterpret_cast<char *>(&num);
    std::cout << "First byte: " << *charPtr << std::endl;
}
/**
reinterpret_cast

Used for low-level reinterpretation of bit patterns.
Allows casting between unrelated pointer types or integral types and pointers.
*/