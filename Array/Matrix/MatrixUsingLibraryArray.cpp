#include <iostream>
#include <array>

// 5. Using std::array
// Fixed-size, safer, and easier to use than built-in arrays:

const int ROWS = 3, COLS = 3;

int main()
{
    std::array<std::array<int, COLS>, ROWS> matrix = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};

    // Access elements
    for (const auto &row : matrix)
    {
        for (const auto &val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
