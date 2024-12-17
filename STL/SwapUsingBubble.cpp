/**SwapUsingBubble.cpp */

#include <iostream>
using namespace std;

// Template function to swap two elements
template <class T>
void swapElements(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template class for a dynamic array and bubble sort
template <class T>
class BubbleSorter {
    T* arr;  // Pointer to dynamic array
    int size;

public:
    // Constructor to allocate memory and initialize the array
    BubbleSorter(int n) {
        this->size = n;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;  // Initialize all elements to 0
        }
    }

    // Destructor to deallocate memory
    ~BubbleSorter() {
        delete[] arr;
    }

    // Method to populate the array
    void populateArray(T* inputArray) {
        for (int i = 0; i < size; i++) {
            arr[i] = inputArray[i];
        }
    }

    // Method to perform bubble sort
    void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {//about this outter loop from first index  before the last index
            for (int j = 0; j < size - i - 1; j++) { //about this inner loop from first index and [upto last index when i = 0, then upto one before of last index when i = 1, then two element before last index when i = 2 and so on]
                if (arr[j] > arr[j + 1]) {
                    swapElements(arr[j], arr[j + 1]);// sorting in increase order
                }
            }
        }
    }

    // Method to display the array
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Bubble Sort with Template Class and Function" << endl;

    // Example with integers
    int intArray[] = {64, 34, 25, 12, 22, 11, 90};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    BubbleSorter<int> intSorter(intSize);
    intSorter.populateArray(intArray);

    cout << "Original integer array: ";
    intSorter.display();

    intSorter.bubbleSort();

    cout << "Sorted integer array: ";
    intSorter.display();

    // Example with floating-point numbers
    double floatArray[] = {4.5, 2.3, 5.8, 1.2, 3.7};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    BubbleSorter<double> floatSorter(floatSize);
    floatSorter.populateArray(floatArray);

    cout << "Original float array: ";
    floatSorter.display();

    floatSorter.bubbleSort();

    cout << "Sorted float array: ";
    floatSorter.display();

    return 0;
}

/**
 * Explanation of the Program:
Template Function for Swap:

The swapElements function is a generic function to swap two variables of any type using references. It is used in the bubbleSort method.
Template Class for Bubble Sort:

The BubbleSorter class is a generic class that supports dynamic memory allocation for arrays of any type.
Dynamic Array: The constructor allocates memory for the array, and the destructor releases it to prevent memory leaks.
populateArray Method: Populates the array with the input array.
bubbleSort Method: Implements the bubble sort algorithm, using the swapElements function for element swapping.
Demonstration in main:

Demonstrates sorting for both an integer array and a floating-point array using the BubbleSorter template class.
Output:

Bubble Sort with Template Class and Function
Original integer array: 64 34 25 12 22 11 90 
Sorted integer array: 11 12 22 25 34 64 90 
Original float array: 4.5 2.3 5.8 1.2 3.7 
Sorted float array: 1.2 2.3 3.7 4.5 5.8
Memory Efficiency:
The dynamic array allocation ensures that only as much memory as needed is allocated, making it suitable for memory-intensive operations.
The destructor ensures proper cleanup of allocated resources, preventing memory leaks.
This implementation is both versatile and efficient, thanks to the use of templates for type generality and dynamic memory management.

The code snippet:


int intArray[] = {64, 34, 25, 12, 22, 11, 90};
int intSize = sizeof(intArray) / sizeof(intArray[0]);
Explanation of the Logic
Declaring the Array:


int intArray[] = {64, 34, 25, 12, 22, 11, 90};
This initializes an array named intArray of type int with 7 elements: {64, 34, 25, 12, 22, 11, 90}.
The array size is implicitly determined from the number of elements in the initializer list, i.e., 7.
Calculating the Total Size of the Array:


sizeof(intArray)
The sizeof operator returns the total size in bytes of the intArray.
Since the array contains 7 int elements and the size of an int is typically 4 bytes (on most systems), the total size of the array would be:
sizeof(intArray)=7×4=28bytes

Calculating the Size of One Element:


sizeof(intArray[0])
The sizeof operator applied to the first element (intArray[0]) returns the size of a single int.
On most systems, this is typically 4 bytes.
Determining the Number of Elements:


int intSize = sizeof(intArray) / sizeof(intArray[0]);
The total number of elements in the array is calculated by dividing the total size of the array (sizeof(intArray)) by the size of one element (sizeof(intArray[0])).
Using the values from above:
intSize = sizeof(intArray)/sizeof(intArray[0]) = 28/4 = 7

Thus, intSize is 7, representing the number of elements in the array.
Why Use This Calculation?
Flexibility:

This method works even if the size of the array changes. For example, if more elements are added to intArray, the sizeof calculation will automatically adjust to reflect the new size.
Avoiding Hardcoding:

Instead of manually specifying the size (e.g., int intSize = 7;), this method calculates it dynamically, reducing the chances of errors when modifying the code.
Portable:

The calculation is portable across systems, as the size of int or other data types might vary depending on the platform.
Summary
The line:


int intSize = sizeof(intArray) / sizeof(intArray[0]);
calculates the number of elements in the array intArray by dividing the total memory size of the array (sizeof(intArray)) by the memory size of a single element (sizeof(intArray[0])). This approach is dynamic, robust, and avoids manual counting or hardcoding of the array size.



The display method:


void display() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
Key Features and Explanation
1. Use of const Keyword
The method is declared as:


void display() const
The const keyword after the method signature indicates that this method does not modify the state of the object (i.e., it does not change any member variables).
When a method is marked as const, it:
Cannot modify any non-mutable data members of the class.
Cannot call any non-const methods on the object.
Allows the method to be called on const objects.
Example:

class MyClass {
private:
    int x;

public:
    MyClass(int val) : x(val) {}

    void display() const {
        cout << "Value: " << x << endl;
    }

    void modify(int newVal) {
        x = newVal;  // Modifies the state
    }
};

int main() {
    const MyClass obj(5);  // Object declared as const
    obj.display();         // Allowed, as display() is const
    // obj.modify(10);     // Error, modify() is non-const
    return 0;
}
2. Purpose of the display Method
This method prints the elements of the array arr to the console.
The const keyword ensures that while iterating and printing, the object itself is not modified.
3. How it Works
It uses a for loop to iterate over the array arr up to the value of size.

Inside the loop:


cout << arr[i] << " ";
Prints each element of the array followed by a space.
After the loop:


cout << endl;
Ensures the output ends with a newline for better formatting.
Why const is Important Here
Safety: Declaring the method as const guarantees that it will not accidentally alter the object's state, making it safer to use.
Read-Only Operations: Since display is meant only for showing data, marking it const clarifies that it’s a read-only operation.
Compatibility with const Objects: The method can be called on both const and non-const objects, increasing flexibility.
Summary
The display method:

Prints the array arr to the console without modifying it.
Is marked const to ensure it cannot modify any member variables or call non-const methods.
The use of const makes the method suitable for use with both const and non-const objects, ensuring safety and clarity in intent.
 */