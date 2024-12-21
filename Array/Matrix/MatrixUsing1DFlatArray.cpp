#include <iostream>

// 4. Using a 1D Flat Array
// Simulate a 2D matrix using a 1D array for better cache performance:
int main()
{
    int rows = 3, cols = 3;
    int *matrix = new int[rows * cols];

    // Access with matrix[i][j] = matrix[i * cols + j]
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i * cols + j] = i * cols + j;
            std::cout << matrix[i * cols + j] << " ";
        }
        std::cout << std::endl;
    }

    delete[] matrix;
    return 0;
}
