/* Vector.cpp */
#include <iostream>
using namespace std;

class Vector
{
private:
    int *v;
    int size;

public:
    // Constructor to initialize the vector with a given size
    Vector(int m)
    {
        size = m;
        v = new int[size]; // Allocate memory for the vector
        for (int i = 0; i < size; i++)
        {
            v[i] = 0; // Initialize elements to 0
        }
    }

    // Constructor to initialize the vector with an array of integers
    Vector(int *ptrToIntArray, int m)
    {
        size = m;
        v = new int[size]; // Allocate memory for the vector
        for (int i = 0; i < size; i++)
        {
            v[i] = ptrToIntArray[i]; // Copy values from the array
        }
    }

    // Destructor to free dynamically allocated memory
    ~Vector()
    {
        delete[] v; // Free the allocated memory
    }

    // Overload * operator for dot product calculation
    int operator*(Vector &inVector)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += this->v[i] * inVector.v[i];
        }
        return sum;
    }

    // Method to assign a raw array to the vector
    void assign(int *ptrToIntArray)
    {
        for (int i = 0; i < size; i++)
        {
            v[i] = ptrToIntArray[i]; // Copy values from the array to the vector
        }
    }
};

int main()
{
    cout << "Vector using C++ Implementation" << endl;

    int x[3] = {1, 2, 3};
    int y[3] = {4, 5, 6};

    // Create two vector objects
    Vector v1(3); // Create a vector of size 3
    v1.assign(x); // Assign values from array x to v1
    Vector v2(3); // Create another vector of size 3
    v2.assign(y); // Assign values from array y to v2

    // Calculate the dot product of the two vectors
    int result = v1 * v2;
    // int result = v1.operator*(v2);//its also ok
    cout << "Result: " << result << endl;

    return 0;
}
/*
Your C++ code has a few issues, particularly around memory allocation and assignment to vectors. Let's go through the errors and fix them one by one:

Uninitialized size in constructor: In the constructor that accepts an integer m, you're using new int[size = m], but size is being set after you're allocating memory. This is problematic because size isn't initialized correctly before the memory allocation. The correct approach is to initialize size directly.

Assignment from raw array to Vector object: You are attempting to assign an array x to an object v1, but this syntax is incorrect. You need to use a method to properly assign values to the vector.

Fixing the second constructor: The second constructor expects an array of integers, but you're not setting size before accessing v[]. You need to initialize the size of the vector in the constructor.

Operator Overloading: The operator * is working correctly, but you should ensure that it can handle vectors with matching sizes.

Key Changes and Fixes:
Constructor for initializing from array: The second constructor now accepts both the array and its size as parameters. This fixes the issue where the size was not set before using it.

Memory Deallocation: Added a destructor ~Vector() to free the dynamically allocated memory when the object is destroyed to prevent memory leaks.

Assignment Method: Replaced the incorrect assignment of an array directly to the vector object with a method assign(). This method copies the contents of the array into the vector's internal array.

Correct Memory Allocation: The constructor now properly initializes size before allocating memory for the vector.

Expected Output:

Vector using C++ Implementation
Result: 32
This output comes from the dot product calculation 1*4 + 2*5 + 3*6 = 4 + 10 + 18 = 32.
*/