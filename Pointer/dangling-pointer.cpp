#include <iostream>

void danglingPointerExample()
{
    int *ptr = new int(42); // Dynamically allocate memory for an integer
    std::cout << "Value: " << *ptr << std::endl;

    delete ptr; // Free the allocated memory

    // Now `ptr` is a dangling pointer.
    std::cout << "Value after delete: " << *ptr << std::endl; // Undefined behavior
}

int *returnDanglingPointer()
{
    int localVar = 10;
    return &localVar; // Returning address of a local variable (dangling pointer)
}

int main()
{
    // Example 1: Using a dangling pointer
    danglingPointerExample();

    // Example 2: Function returning a dangling pointer
    int *dangling = returnDanglingPointer();
    std::cout << "Dangling pointer value: " << *dangling << std::endl; // Undefined behavior

    return 0;
}
/**


A dangling pointer is a pointer that points to a memory location that has already been deallocated or freed. Using a dangling pointer can lead to undefined behavior, as the memory location it points to may no longer be valid.

Causes of Dangling Pointers
Deallocation of memory: If memory is deallocated and the pointer still points to it.
Out of scope: When an object goes out of scope, and the pointer points to that object.
Function returning a local address: Returning the address of a local variable in a function.
Example in C++
Here’s an example to illustrate the issue:

cpp
Copy code
#include <iostream>

void danglingPointerExample() {
    int* ptr = new int(42);  // Dynamically allocate memory for an integer
    std::cout << "Value: " << *ptr << std::endl;

    delete ptr;  // Free the allocated memory

    // Now `ptr` is a dangling pointer.
    std::cout << "Value after delete: " << *ptr << std::endl; // Undefined behavior
}

int* returnDanglingPointer() {
    int localVar = 10;
    return &localVar;  // Returning address of a local variable (dangling pointer)
}

int main() {
    // Example 1: Using a dangling pointer
    danglingPointerExample();

    // Example 2: Function returning a dangling pointer
    int* dangling = returnDanglingPointer();
    std::cout << "Dangling pointer value: " << *dangling << std::endl; // Undefined behavior

    return 0;
}
Explanation
In danglingPointerExample:

The memory allocated using new is deleted using delete.
Accessing the pointer after the deletion results in undefined behavior.
In returnDanglingPointer:

The function returns the address of a local variable (localVar).
When the function scope ends, the memory for localVar is released.
The returned pointer now points to invalid memory.
Avoiding Dangling Pointers
Set the pointer to nullptr after deleting it:
cpp
Copy code
delete ptr;
ptr = nullptr; // Safe: The pointer no longer points to the deallocated memory.
Avoid returning addresses of local variables:
Use dynamically allocated memory or return by value.
Use smart pointers (e.g., std::unique_ptr or std::shared_ptr in C++) to manage memory automatically and avoid manual deletion.
By following best practices, dangling pointer issues can be minimized, making programs safer and more robust.







*/