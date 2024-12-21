#include <iostream>
#define ROWS 3
#define COLS 3
// 1. Using a Fixed-Size Array
// For a 2D matrix with a known size at compile time :
int main()
{
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Access elements
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
