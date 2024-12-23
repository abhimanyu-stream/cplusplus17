#include <iostream>
#include <memory>

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
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(20); // Create a shared_ptr
    {
        std::shared_ptr<MyClass> ptr2 = ptr1; // Share ownership
        ptr2->display();
        ptr2->modifiying();
        std::cout << "Reference count: " << ptr1.use_count() << "\n";
    } // ptr2 goes out of scope, reference count decreases

    std::cout << "Reference count: " << ptr1.use_count() << "\n";
    ptr1->display();
    return 0; // ptr1 goes out of scope, and MyClass is destroyed
}
/**
std::shared_ptr
Description: Represents shared ownership of a dynamically allocated object. Multiple std::shared_ptr instances can own the same object.
Key Points:
Uses reference counting to track how many std::shared_ptr instances own the object.
Deletes the object when the last std::shared_ptr goes out of scope.
Thread-safe reference counting but not the managed object itself.
*/