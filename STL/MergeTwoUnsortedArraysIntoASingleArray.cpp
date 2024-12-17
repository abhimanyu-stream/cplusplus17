/*MergeTwoUnsortedArraysIntoASingleArray.cpp*/

#include <iostream>
using namespace std;

template <class T>
class Array {
    T* array;  // Pointer to hold the dynamic array
    int size;  // Size of the array

public:
    // Default constructor
    Array() : array(nullptr), size(0) {}

    // Constructor to initialize the array with a given size
    Array(int m) {
        this->size = m;
        array = new T[size];  // Allocate memory for T, not int
    }

    // Constructor to initialize the array with existing data
    Array(T* ptrToArray, int size) {
        this->size = size;
        array = new T[size];  // Allocate memory for T
        for (int i = 0; i < size; i++) {
            array[i] = ptrToArray[i];  // Copy elements from the input array
        }
    }

    // Destructor to free dynamically allocated memory
    ~Array() {
        delete[] array;
    }

    // Function to get the pointer to the array
    T* getArray() const {
        return this->array;
    }

    // Function to get the size of the array
    int getSize() const {
        return this->size;
    }

    // Method to display the array elements
    void showArrayElements() const {
        for (int i = 0; i < size; i++) {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }
};

// Template function to merge two arrays
template <class T>
Array<T> mergeToUnSortedArray(Array<T>& ArrayFirst, Array<T>& ArraySecond) {
    // Calculate the total size of the merged array
    int newSize = ArrayFirst.getSize() + ArraySecond.getSize();

    // Create the merged array
    Array<T> mergedArray(newSize);

    // Pointer to merged array's internal array
    T* mergedData = mergedArray.getArray();

    // Sort the given arrays in place
    sortArray(ArrayFirst);
    sortArray(ArraySecond);

    // Pointer to the first and second arrays
    const T* firstData = ArrayFirst.getArray();
    const T* secondData = ArraySecond.getArray();

    // Copy elements from the first array
    for (int i = 0; i < ArrayFirst.getSize(); i++) {
        mergedData[i] = firstData[i];
    }

    // Copy elements from the second array
    for (int i = 0; i < ArraySecond.getSize(); i++) {
        mergedData[ArrayFirst.getSize() + i] = secondData[i];
    }

    return mergedArray;  // Return the merged array
}
// Template function to swap two elements
template <class T>
void swapElements(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
// Template function to sort an array in place
template <class T>
void sortArray(Array<T>& array) {
    T* data = array.getArray();
    int size = array.getSize();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swapElements(data[j], data[j + 1]);
            }
        }
    }
}



int main() {
    int x[] = {64, 34, 25, 12, 22, 11, 90};
    int sizeX = sizeof(x) / sizeof(x[0]);

    int y[] = {33, 56, 78, 99, 10, 4, 7};
    int sizeY = sizeof(y) / sizeof(y[0]);

    // Create Array objects using the template class
    Array<int> array1(x, sizeX);
    Array<int> array2(y, sizeY);

    Array<int> mergedSortedArray = mergeToUnSortedArray(array1, array2);

    cout << "Merged and Sorted Array:" << endl;
    mergedSortedArray.showArrayElements();

    return 0;
}

/*
The correct syntax is:


Array<T>& arr1
Explanation
Array<T>& arr1: This declares a reference to an Array<T> object. Using a reference avoids copying the entire object, which is more efficient, especially for larger objects. It allows the function to operate directly on the original object without creating a duplicate.

Array<T> &arr1: This is also valid in C++ because spacing around the & does not matter. However, the convention is to place the & closer to the type (Array<T>&), as it improves readability and makes it clear that it's a reference type.

Correct Usage in Context
Here's how you should define the function signature:


template <class T>
Array<T> mergeToUnsortedArray(const Array<T>& arr1, const Array<T>& arr2) {
    // Implementation
}
In this case:

const Array<T>& arr1: This passes arr1 as a constant reference, preventing modification of the input object.
Similarly, const Array<T>& arr2: Ensures that the second input array is not modified.


*/