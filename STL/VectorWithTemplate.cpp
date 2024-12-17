/** VectorWithTemplate.cpp g++ compiler */

/** VectorWithTemplate.cpp
 * Compiled with: g++ -std=c++17 -O3 -o VectorWithTemplate.exe VectorWithTemplate.cpp
 */

/** VectorWithTemplate.cpp
 * Compiled with: g++ -std=c++17 -O3 -o VectorWithTemplate.exe VectorWithTemplate.cpp
 */

#include <iostream>
using namespace std;

template <class T>
class VectorWithTemplate {
    T* v;      // Pointer to hold the array
    int size;  // Size of the vector

public:

    VectorWithTemplate(){}

    // Constructor to initialize the vector with a given size
    VectorWithTemplate(int m) {
        this->size = m;
        v = new T[size];  // Allocate memory for the vector
        for (int i = 0; i < size; i++) {
            v[i] = 0;  // Initialize elements to 0
        }
    }

    // Constructor to initialize the vector with an array
    VectorWithTemplate(T* ptrToArray, int m) {
         this->size = m;
         v = new T[size];  // Allocate memory for the vector
         for (int i = 0; i < size; i++) {
             v[i] = ptrToArray[i];  // Copy values from the array
         }
     }

    // Overloaded * operator for dot product calculation
    T operator*(VectorWithTemplate& inVector) {
        if (this->size != inVector.size) {
            throw runtime_error("Vectors must be of the same size for dot product.");
        }

        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += this->v[i] * inVector.v[i];
        }
        return sum;
    }

    // Method to assign values from a raw array to the vector
    void assign(T* ptrToArray, int length) {
        if (this->size != length) {
            throw runtime_error("Array size must match vector size.");
        }
        for (int i = 0; i < size; i++) {
            v[i] = ptrToArray[i];  // Copy values from the array to the vector
        }
    }

    void show(){

        cout <<"size "<<this->size<<endl;
        cout <<"v ";
        for (int i = 0; i < size; i++) {
            cout<<this->v[i]<<" ";
        }
        cout<<endl;
    }

    // Destructor to free dynamically allocated memory
    ~VectorWithTemplate() {
        delete[] v;
    }
};

int main() {
    cout << "Vector Implementation with Template Class" << endl;

    int x[3] = {1, 2, 3};
    int y[3] = {4, 5, 6};

    // Create vector objects using the template class
    VectorWithTemplate<int> v1(3);
    VectorWithTemplate<int> v2(3);

    // Assign values from arrays to the vectors
    v1.assign(x, 3);
    v2.assign(y, 3);

    // Calculate the dot product of the vectors
    int result = v1 * v2;

    // Display the result
    cout << "Result of dot product: " << result << endl;

    VectorWithTemplate<int> v3;
    v3 = v1;
    v3.show();


    //To use the constructor VectorWithTemplate(T* ptrToArray, int m) from the main() function, you need to pass a raw array (e.g., int x[3]) and its size as arguments when creating an object of VectorWithTemplate. This constructor directly initializes the vector with the values from the array.

    //Here's how you can modify your main() function to use this constructor:     
    // Create vector objects using the template class and the array constructor
    VectorWithTemplate<int> v4(x, 3); // Directly initialize v1 with array x
    VectorWithTemplate<int> v5(y, 3); // Directly initialize v2 with array y
    v4.show();
    v5.show();

    return 0;
}
