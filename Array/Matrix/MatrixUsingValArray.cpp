#include <iostream>
#include <valarray>

// 6. Using std::valarray
// A 1D array that provides mathematical operations:
// Similar to the 1D flat array, but with additional mathematical operations.
// The valarray class is a simplified version of the array class that is designed to work with mathematical operations.
// It provides a convenient way to perform element-wise operations on arrays, such as addition, subtraction, multiplication, and division.
// The valarray class is part of the C++ Standard Library and is defined in the <valarray> header.
// To use the valarray class, you need to include the <valarray> header file.
// The valarray class provides a number of member functions that allow you to perform various mathematical operations on arrays.
// For example, you can use the sum() function to calculate the sum of all elements in an array, the max() function to find the maximum element in an array, and the apply() function to apply a function to each element in an array.
// The valarray class also provides overloaded operators for performing element-wise arithmetic operations, such as addition, subtraction, multiplication, and division.
// The valarray class is a useful tool for working with arrays in C++ and can simplify many common array operations.
// The valarray class is a versatile tool for working with arrays in C++ and can simplify many common array operations.
// The valarray class provides a number of member functions that allow you to perform various mathematical operations on arrays, such as addition, subtraction, multiplication, and division.
// The valarray class also provides overloaded operators for performing element-wise arithmetic operations, such as addition, subtraction, multiplication, and division.
// The valarray class is a useful tool for working with arrays in C++ and can simplify many common array operations.
// The valarray class is a versatile tool for working with arrays in C++ and can simplify many common array operations.
// The valarray class provides a number of member functions that allow you to perform various mathematical operations on arrays, such as addition, subtraction, multiplication, and division.
// The valarray class is a versatile tool for working with arrays in C++ and can simplify many common array operations.

int main()
{
    const int rows = 3, cols = 3;
    std::valarray<int> matrix(rows * cols);

    // Initialize
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i * cols + j] = i * cols + j;

    // Access and print
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
