#include <iostream>

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
    // Example 1: Numeric Conversion
    double num = 3.14;
    int integer = static_cast<int>(num);
    std::cout << "Converted integer: " << integer << std::endl;

    // Example 2: Casting in Inheritance
    Derived derivedObj;
    Base *basePtr = &derivedObj;

    basePtr->display(); // Derived class

    // Base base;
    // base.display();//Base class

    // Upcasting (implicit)
    Derived *derivedPtr = static_cast<Derived *>(basePtr); // Downcasting
    derivedPtr->display();                                 // Derived class

    // Example 3: Casting void pointer
    int x = 42;
    void *voidPtr = &x;
    int *intPtr = static_cast<int *>(voidPtr);
    std::cout << "Value via static_cast: " << *intPtr << std::endl;

    return 0;
}

/**
static_cast in C++
static_cast is a type of casting operator in C++ that performs a compile-time type conversion. It is safer and more explicit than C-style casting because it only allows conversions that are well-defined and checked at compile-time.

Syntax:
cpp
Copy code
static_cast<type>(expression)
Key Features:
Performs type conversion between compatible types.
Can be used to cast up or down an inheritance hierarchy (but does not check the type safety at runtime).
Converts between numeric types, pointers, and enums.
Cannot perform a const_cast or dynamic_cast.
Example of static_cast
cpp
Copy code
#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class\n";
    }
};

int main() {
    // Example 1: Numeric Conversion
    double num = 3.14;
    int integer = static_cast<int>(num);
    std::cout << "Converted integer: " << integer << std::endl;

    // Example 2: Casting in Inheritance
    Derived derivedObj;
    Base* basePtr = &derivedObj; // Upcasting (implicit)
    Derived* derivedPtr = static_cast<Derived*>(basePtr); // Downcasting
    derivedPtr->display();

    // Example 3: Casting void pointer
    int x = 42;
    void* voidPtr = &x;
    int* intPtr = static_cast<int*>(voidPtr);
    std::cout << "Value via static_cast: " << *intPtr << std::endl;

    return 0;
}
Real-Time Use Case of static_cast
Numeric Conversions:

Converting between numeric types (e.g., from double to int) is common in applications like financial calculations or physics simulations where exact data representation is critical.
Object Casting:

When working with polymorphic objects, static_cast is used to convert between base and derived class pointers or references if the programmer knows the object type at compile-time.
Other Type Casts in C++ (C++17)
dynamic_cast

Used for safe type casting in an inheritance hierarchy.
Performs a runtime check and returns nullptr if the cast is invalid.
Works only with polymorphic base classes (those with at least one virtual function).
cpp
Copy code
Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Valid cast
if (derivedPtr) {
    derivedPtr->display();
} else {
    std::cout << "Invalid cast\n";
}
const_cast

Used to add or remove const or volatile qualifiers from a variable.
Does not change the actual const-ness of the object in memory.
cpp
Copy code
const int num = 10;
int* numPtr = const_cast<int*>(&num);
*numPtr = 20; // Undefined behavior if `num` was truly const
reinterpret_cast

Used for low-level reinterpretation of bit patterns.
Allows casting between unrelated pointer types or integral types and pointers.
cpp
Copy code
int num = 65;
char* charPtr = reinterpret_cast<char*>(&num);
std::cout << "First byte: " << *charPtr << std::endl;
C-style Cast

The old, less safe style of casting. Equivalent to trying const_cast, static_cast, or reinterpret_cast in a single operation.
Should be avoided in modern C++.
cpp
Copy code
int num = 42;
double result = (double)num; // C-style cast
Comparison of Casts
Cast	Use Case	Runtime Check	Safety
static_cast	Compatible types, up/downcasting	No	Safer than C-style
dynamic_cast	Polymorphic type checking in inheritance	Yes	Safe
const_cast	Add/remove const/volatile qualifiers	No	Requires caution
reinterpret_cast	Low-level reinterpretation of data	No	Unsafe
C-style Cast	General casting (unspecified behavior)	No	Unsafe
Best Practices:
Prefer static_cast for well-defined, compile-time conversions.
Use dynamic_cast when runtime type checking is required.
Avoid reinterpret_cast unless absolutely necessary, such as in hardware programming or low-level optimizations.
Replace C-style casts with the appropriate modern cast for clarity and safety.













*/