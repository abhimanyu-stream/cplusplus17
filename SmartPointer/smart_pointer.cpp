/**
C++ provides three types of smart pointers in the Standard Template Library (STL): std::unique_ptr, std::shared_ptr, and std::weak_ptr. These smart pointers manage the lifetime of dynamically allocated objects and help avoid common memory management issues like memory leaks and dangling pointers.

1. std::unique_ptr
Description: Represents sole ownership of a dynamically allocated object. No other smart pointer can share ownership of the same object.
Key Points:
When a std::unique_ptr goes out of scope, it automatically deletes the managed object.
Cannot be copied, but can be moved to transfer ownership.
Example:

cpp
Copy code
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int val) : value(val) { std::cout << "Created MyClass with value " << value << "\n"; }
    ~MyClass() { std::cout << "Destroyed MyClass with value " << value << "\n"; }
    void display() const { std::cout << "Value: " << value << "\n"; }

private:
    int value;
};

int main() {
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(10); // Create a unique_ptr
    ptr1->display();

    // Transfer ownership
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
    if (!ptr1) std::cout << "ptr1 is null\n";

    ptr2->display();
    return 0; // ptr2 goes out of scope, and MyClass is destroyed
}
2. std::shared_ptr
Description: Represents shared ownership of a dynamically allocated object. Multiple std::shared_ptr instances can own the same object.
Key Points:
Uses reference counting to track how many std::shared_ptr instances own the object.
Deletes the object when the last std::shared_ptr goes out of scope.
Thread-safe reference counting but not the managed object itself.
Example:

cpp
Copy code
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int val) : value(val) { std::cout << "Created MyClass with value " << value << "\n"; }
    ~MyClass() { std::cout << "Destroyed MyClass with value " << value << "\n"; }
    void display() const { std::cout << "Value: " << value << "\n"; }

private:
    int value;
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(20); // Create a shared_ptr
    {
        std::shared_ptr<MyClass> ptr2 = ptr1; // Share ownership
        ptr2->display();
        std::cout << "Reference count: " << ptr1.use_count() << "\n";
    } // ptr2 goes out of scope, reference count decreases

    std::cout << "Reference count: " << ptr1.use_count() << "\n";
    ptr1->display();
    return 0; // ptr1 goes out of scope, and MyClass is destroyed
}
3. std::weak_ptr
Description: A weak reference to a std::shared_ptr. Does not contribute to the reference count and does not own the object.
Key Points:
Used to break circular references between std::shared_ptr objects.
Needs to be converted to a std::shared_ptr before accessing the object.
Allows checking if the managed object is still alive using expired() or lock().
Example:

cpp
Copy code
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int val) : value(val) { std::cout << "Created MyClass with value " << value << "\n"; }
    ~MyClass() { std::cout << "Destroyed MyClass with value " << value << "\n"; }
    void display() const { std::cout << "Value: " << value << "\n"; }

private:
    int value;
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(30); // Create a shared_ptr
    std::weak_ptr<MyClass> weakPtr = ptr1; // Create a weak_ptr

    if (auto sharedPtr = weakPtr.lock()) { // Convert weak_ptr to shared_ptr
        sharedPtr->display();
    }

    ptr1.reset(); // Destroy the shared_ptr
    if (weakPtr.expired()) {
        std::cout << "The managed object has been destroyed.\n";
    }

    return 0;
}
Summary Table
Smart Pointer	Ownership	Reference Count	Thread-Safe	Use Cases
std::unique_ptr	Sole	No	N/A	Exclusive ownership, RAII, resource management.
std::shared_ptr	Shared	Yes	Yes	Shared ownership, reference counting.
std::weak_ptr	Non-owning	No	N/A	Break circular dependencies.
By choosing the right smart pointer, you can effectively manage dynamic memory and reduce the risks associated with manual memory management in C++.
*/