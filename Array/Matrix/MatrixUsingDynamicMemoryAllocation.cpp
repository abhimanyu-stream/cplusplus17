#include <iostream>

// 2. Using Dynamic Memory Allocation
// For matrices where size is decided at runtime:

int main()
{
    int rows = 3, cols = 3;
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];

    // Initialize and print
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = i * cols + j;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free memory
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
