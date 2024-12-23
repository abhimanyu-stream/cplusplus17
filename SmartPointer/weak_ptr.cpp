#include <iostream>
#include <memory>
#include <string>

class MyClass
{
public:
    MyClass(int val) : value(val) { std::cout << "Created MyClass with value " << value << "\n"; }
    ~MyClass() { std::cout << "Destroyed MyClass with value " << value << "\n"; }
    void display() const { std::cout << "Value: " << value << "\n"; }
    void modifiying()
    {
        value = 400;
        std::cout << "Value: " << value << "\n";
    }

private:
    int value;
};

int main()
{
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(30); // Create a shared_ptr
    std::weak_ptr<MyClass> weakPtr = ptr1;                         // Create a weak_ptr
    std::cout << "Reference count: " << ptr1.use_count() << "\n";  // 1
    if (auto sharedPtr = weakPtr.lock())
    { // Convert weak_ptr to shared_ptr

        std::string typeidweakPtr = typeid(weakPtr).name();
        std::cout << typeidweakPtr << std::endl;
        std::cout << typeid(sharedPtr).name() << std::endl;
        std::string typeidsharedPtr = typeid(sharedPtr).name();

        sharedPtr->display();                                         // Value: 30
        sharedPtr->modifiying();                                      // Value: 400
        std::cout << "Reference count: " << ptr1.use_count() << "\n"; // 2
    }

    ptr1.reset(); // Destroy the shared_ptr.   // output: Destroyed MyClass with value 30. Reference count: 0 . The managed object has been destroyed.
    if (weakPtr.expired())
    {
        std::cout << "The managed object has been destroyed.\n"; // output: The managed object has been destroyed.
    }

    // sharedPtr->display(); output: error: ‘sharedPtr’ was not declared in this scope
    // sharedPtr->modifiying(); output: error: ‘sharedPtr’ was not declared in this scope

    // below code will give error because ptr1 is not declared in this scope

    // ptr1->display();    // output: error: ‘ptr1’ was not declared in this scope.
    // ptr1->modifiying(); // output: error: ‘ptr1’ was not declared in this scope
    return 0;
}
/**



how to use makefile:

make sure about the path of g++ compiler in your system.

A) for c program

# Compiler
#CC = gcc

# Compiler flags
# CFLAGS = -Wall -Wextra -std=c17
$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $(TARGET) $(SRC)
-----------------------------------------------------------------------------------
B) for cpp program
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra
$(TARGET): $(SRC)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

-----------------------------------------------------------------------------------
E:\1ws-abhimanyu\C++Programs\cplusplus17\SmartPointer>make
g++ -std=c++17 -Wall -Wextra  -o weak_ptr.exe weak_ptr.cpp

E:\1ws-abhimanyu\C++Programs\cplusplus17\SmartPointer>weak.exe
Created MyClass with value 30
Reference count: 1
St8weak_ptrI7MyClassE
St10shared_ptrI7MyClassE
Value: 30
Value: 400
Reference count: 2
Destroyed MyClass with value 400
The managed object has been destroyed.
Value:
E:\1ws-abhimanyu\C++Programs\cplusplus17\SmartPointer>







std::weak_ptr
Description: A weak reference to a std::shared_ptr. Does not contribute to the reference count and does not own the object.
Key Points:
Used to break circular references between std::shared_ptr objects.
Needs to be converted to a std::shared_ptr before accessing the object.
Allows checking if the managed object is still alive using expired() or lock().





*/