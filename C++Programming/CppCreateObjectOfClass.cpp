
/**CppCreateObjectOfClass.cpp*/

#include<iostream>
#include<string>
using namespace std;



/**Class A 
1. Default Constructor
When a class has a default constructor (either explicitly defined or the compiler-provided default), objects can be created without passing arguments.
*/
class A {
public:
    A() {
        cout << "Default constructor called" << endl;
    }
};

/**Class B
* 2. Parameterized Constructor You can create an object by passing arguments to a parameterized constructor.
*/
class B {
public:
    B(int x, int y) {
        cout << "Parameterized constructor called: x = " << x << ", y = " << y << endl;
    }
};

/**3. Dynamic Object Creation
Objects can be dynamically created using the new operator. */
class C {
public:
    C() {
        cout << "Dynamic object created" << endl;
    }
};

/**4. Copy Constructor
Objects can be created as a copy of another object using the copy constructor. */
class D {
public:
    D() {}
    D(const D& obj) {
        cout << "Copy constructor called" << endl;
    }
};
/**5. Using Initializer Lists
You can initialize objects using an initializer list. */
class E {
public:
    int x, y;

    E(int a, int b) : x(a), y(b) {}
};
/**6. Using a Factory Method
Objects can be created using a factory method, which is a method designed to return objects. */
class F {
public:
    static F createObject() {
        return F();
    }
};
/**7. Aggregate Initialization
For classes with public members and no user-defined constructors, aggregate initialization can be used. */
class G {
public:
    int a, b;
};
/**8. Using Smart Pointers (Modern C++)
Modern C++ uses smart pointers for managing dynamic objects. */
#include <memory>
class H {
public:
    H() {
        cout << "Smart pointer object created" << endl;
    }
};
/**9. Using Placement new
You can use placement new to create objects at a specific memory location. */
#include <iostream>
#include <new>

class I {
public:
    I(int x) {
        cout << "Placement new: " << x << endl;
    }
};

/**10. Array of Objects
Objects can also be created as an array. */
class J {
public:
    J() {
        cout << "Array object created" << endl;
    }
};

int main() {

    /** Various ways to call Constructor in C++ to create Object of Class*/
    

    /** Class A */
    A objA1; // Default constructor called
    A objA2 = A(); // Explicit default constructor invocation

    /**Class B */
    B objB1(10, 20); // Direct initialization
    B objB2 = B(30, 40); // Explicit initialization

    /**Class C */
    C* obCj = new C(); // Object created on the heap
    delete obCj;       // Free the allocated memory

    /**Class D */
    D objD1;           // Default constructor
    D objD2 = objD1;    // Copy constructor
    D objD3(objD1);     // Copy constructor

    /**Class E */
    E objE1{10, 20};  // Brace-enclosed initializer
    E objE2 = {30, 40}; // Equivalent to direct initialization

    /**Class F */
    F objF = F::createObject(); // Created using factory method
    /**Class G */
    G objG = {1, 2}; // Aggregate initialization
    /**Class H */
    std::shared_ptr<H> objH1 = std::make_shared<H>();
    std::unique_ptr<H> objH2 = std::make_unique<H>();
    /**Class I */
    char buffer[sizeof(I)];
    I* objI = new (buffer) I(42); // Object created in buffer

    /**Class J */
    J arr[3]; // Array of 3 objects








    return 0;
}
/**Here are various ways to create objects in C++:

Default Constructor
Parameterized Constructor
Dynamic Object Creation
Copy Constructor
Using Initializer Lists
Using a Factory Method
Aggregate Initialization
Using Smart Pointers
Placement new
Array of Objects */