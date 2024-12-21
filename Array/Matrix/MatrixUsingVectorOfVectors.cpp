#include <iostream>
#include <vector>

// 3. Using std::vector
// Dynamic, safer, and easy to use:

// Function prototypes
bool canAddOrSubtract(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1);
bool canMultiply(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1);
bool isSquare(const std::vector<std::vector<int>> &A1);
bool isDiagonal(const std::vector<std::vector<int>> &A1);
bool isIdentity(const std::vector<std::vector<int>> &A1);
bool isSparse(const std::vector<std::vector<int>> &A1, double sparsityThreshold = 0.7);
bool isSymmetric(const std::vector<std::vector<int>> &A1);

bool isSkewSymmetric(const std::vector<std::vector<int>> &A1);
void matrixAddition(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1);
void matrixSubtraction(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1);
void matrixMultiplication(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1);
void matrixTranspose(const std::vector<std::vector<int>> &A1);
int sumMainDiagonal(const std::vector<std::vector<int>> &A1);
int sumMinorDiagonal(const std::vector<std::vector<int>> &A1);
void identityMatrix(int n);
void sparseMatrixRepresentation(const std::vector<std::vector<int>> &A1);
int determinant(std::vector<std::vector<int>> A1);

int main()
{
    // Define the dimensions of the matrix
    const int rows = 3;
    const int cols = 3;

    // Create a 2D matrix using a vector of vectors
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> mymatrix(rows, std::vector<int>(cols, 0));

    // Initialize the matrix with some values
    int value = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = value++;
        }
    }

    // Print the matrix
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // Print the matrix
    std::cout << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << mymatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::vector<std::vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    std::cout << "Matrix Addition:\n";
    matrixAddition(A, B);

    std::cout << "\nMatrix Subtraction:\n";
    matrixSubtraction(A, B);

    std::cout << "\nMatrix Multiplication:\n";
    matrixMultiplication(A, B);

    std::cout << "\nMatrix Transpose:\n";
    matrixTranspose(A);

    std::cout << "\nSum of Main Diagonal: " << sumMainDiagonal(A) << std::endl;
    std::cout << "Sum of Minor Diagonal: " << sumMinorDiagonal(A) << std::endl;

    std::cout << "\nIdentity Matrix (3x3):\n";
    identityMatrix(3);

    std::cout << "\nSparse Matrix Representation:\n";
    sparseMatrixRepresentation(A);

    std::cout << "\nDeterminant: " << determinant(A) << std::endl;
    /**
Matrix Operations and Their Conditions in C++
Here, we discuss the necessary conditions for common matrix operations (addition, multiplication, etc.), followed by C++ implementations for condition checks and properties of various matrix types.

1. Necessary Conditions for Matrix Operations
Matrix Addition
Two matrices
𝐴
A and
𝐵
B can be added only if:
They have the same dimensions (
𝑟
𝑜
𝑤
𝑠
𝐴
=
𝑟
𝑜
𝑤
𝑠
𝐵
rows
A
​
 =rows
B
​
  and
𝑐
𝑜
𝑙
𝑠
𝐴
=
𝑐
𝑜
𝑙
𝑠
𝐵
cols
A
​
 =cols
B
​
 ).
Matrix Multiplication
Two matrices
𝐴
A and
𝐵
B can be multiplied only if:
The number of columns in
𝐴
A equals the number of rows in
𝐵
B (
𝑐
𝑜
𝑙
𝑠
𝐴
=
𝑟
𝑜
𝑤
𝑠
𝐵
cols
A
​
 =rows
B
​
 ).
Matrix Subtraction
Same as addition: The dimensions of the two matrices must match.
Transpose
A matrix transpose flips rows and columns, with no specific size restrictions.
Properties of Matrix Types
Square Matrix:
Rows equal columns (
𝑟
𝑜
𝑤
𝑠
=
𝑐
𝑜
𝑙
𝑠
rows=cols).
Diagonal Matrix:
All non-diagonal elements are zero.
Identity Matrix:
Diagonal elements are 1, and all other elements are zero.
Sparse Matrix:
Most elements are zero (
non-zero elements
≪
total elements
non-zero elements≪total elements).
Symmetric Matrix:
𝐴
=
𝐴
𝑇
A=A
T
  (the matrix equals its transpose).
Skew-Symmetric Matrix:
𝐴
=
−
𝐴
𝑇
A=−A
T
 .
Orthogonal Matrix:
𝐴
⋅
𝐴
𝑇
=
𝐼
A⋅A
T
 =I (the matrix product with its transpose equals the identity matrix).


    */
    std::vector<std::vector<int>> A1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> B1 = {{5, 6}, {7, 8}};
    std::vector<std::vector<int>> Identity = {{1, 0}, {0, 1}};
    std::vector<std::vector<int>> Diagonal = {{5, 0}, {0, 10}};
    std::vector<std::vector<int>> Sparse = {{0, 0}, {0, 1}};
    std::vector<std::vector<int>> Symmetric = {{1, 2}, {2, 3}};
    std::vector<std::vector<int>> SkewSymmetric = {{0, -2}, {2, 0}};

    std::cout << "Addition Possible: " << canAddOrSubtract(A1, B1) << std::endl;
    std::cout << "Multiplication Possible: " << canMultiply(A1, B1) << std::endl;

    std::cout << "Is Square: " << isSquare(A1) << std::endl;
    std::cout << "Is Diagonal: " << isDiagonal(Diagonal) << std::endl;
    std::cout << "Is Identity: " << isIdentity(Identity) << std::endl;
    std::cout << "Is Sparse: " << isSparse(Sparse) << std::endl;
    std::cout << "Is Symmetric: " << isSymmetric(Symmetric) << std::endl;
    std::cout << "Is Skew-Symmetric: " << isSkewSymmetric(SkewSymmetric) << std::endl;

    return 0;
} // end main

// Check dimensions for addition or subtraction
bool canAddOrSubtract(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1)
{
    return A1.size() == B1.size() && A1[0].size() == B1[0].size();
}

// Check dimensions for multiplication
bool canMultiply(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1)
{
    return A1[0].size() == B1.size();
}

// Check if a matrix is square
bool isSquare(const std::vector<std::vector<int>> &A1)
{
    return A1.size() == A1[0].size();
}

// Check if a matrix is diagonal
bool isDiagonal(const std::vector<std::vector<int>> &A1)
{
    if (!isSquare(A1))
        return false;
    for (int i = 0; i < A1.size(); ++i)
        for (int j = 0; j < A1[0].size(); ++j)
            if (i != j && A1[i][j] != 0)
                return false;
    return true;
}

// Check if a matrix is identity
bool isIdentity(const std::vector<std::vector<int>> &A1)
{
    if (!isSquare(A1))
        return false;
    for (int i = 0; i < A1.size(); ++i)
        for (int j = 0; j < A1[0].size(); ++j)
            if ((i == j && A1[i][j] != 1) || (i != j && A1[i][j] != 0))
                return false;
    return true;
}

// Check if a matrix is sparse
bool isSparse(const std::vector<std::vector<int>> &A1, double sparsityThreshold)
{
    int zeroCount = 0, totalElements = A1.size() * A1[0].size();
    for (const auto &row : A1)
        for (int val : row)
            if (val == 0)
                ++zeroCount;

    return (double)zeroCount / totalElements >= sparsityThreshold;
}

// Check if a matrix is symmetric
bool isSymmetric(const std::vector<std::vector<int>> &A1)
{
    if (!isSquare(A1))
        return false;
    for (int i = 0; i < A1.size(); ++i)
        for (int j = 0; j < i; ++j)
            if (A1[i][j] != A1[j][i])
                return false;
    return true;
}

// Check if a matrix is skew-symmetric
bool isSkewSymmetric(const std::vector<std::vector<int>> &A1)
{
    if (!isSquare(A1))
        return false;
    for (int i = 0; i < A1.size(); ++i)
        for (int j = 0; j < i; ++j)
            if (A1[i][j] != -A1[j][i])
                return false;
    return true;
}
void matrixAddition(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1)
{
    int rows = A1.size();
    int cols = A1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i][j] = A1[i][j] + B1[i][j];

    // Print result
    for (const auto &row : result)
    {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}
void matrixSubtraction(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1)
{
    int rows = A1.size();
    int cols = A1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i][j] = A1[i][j] - B1[i][j];

    // Print result
    for (const auto &row : result)
    {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}

void matrixMultiplication(const std::vector<std::vector<int>> &A1, const std::vector<std::vector<int>> &B1)
{
    int rows = A1.size();
    int cols = B1[0].size();
    int common = A1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            for (int k = 0; k < common; ++k)
                result[i][j] += A1[i][k] * B1[k][j];

    // Print result
    for (const auto &row : result)
    {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}
void matrixTranspose(const std::vector<std::vector<int>> &A1)
{
    int rows = A1.size();
    int cols = A1[0].size();
    std::vector<std::vector<int>> result(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[j][i] = A1[i][j];

    // Print result
    for (const auto &row : result)
    {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}

int sumMainDiagonal(const std::vector<std::vector<int>> &A1)
{
    int rows = A1.size();
    int sum = 0;
    for (int i = 0; i < rows; ++i)
        sum += A1[i][i];
    return sum;
}
int sumMinorDiagonal(const std::vector<std::vector<int>> &A1)
{
    int rows = A1.size();
    int sum = 0;
    for (int i = 0; i < rows; ++i)
        sum += A1[i][rows - i - 1];
    return sum;
}
void identityMatrix(int n)
{
    std::vector<std::vector<int>> identity(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        identity[i][i] = 1;

    for (const auto &row : identity)
    {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}
void sparseMatrixRepresentation(const std::vector<std::vector<int>> &A1)
{
    std::vector<std::tuple<int, int, int>> sparse;

    for (int i = 0; i < A1.size(); ++i)
        for (int j = 0; j < A1[0].size(); ++j)
            if (A1[i][j] != 0)
                sparse.emplace_back(i, j, A1[i][j]);

    for (const auto &[row, col, val] : sparse)
        std::cout << "(" << row << ", " << col << ", " << val << ")\n";
}
int determinant(std::vector<std::vector<int>> A1)
{
    int n = A1.size();
    if (n == 1)
        return A1[0][0];
    if (n == 2)
        return A1[0][0] * A1[1][1] - A1[0][1] * A1[1][0];

    int det = 0;
    for (int p = 0; p < n; ++p)
    {
        std::vector<std::vector<int>> minor;
        for (int i = 1; i < n; ++i)
        {
            std::vector<int> row;
            for (int j = 0; j < n; ++j)
                if (j != p)
                    row.push_back(A1[i][j]);
            minor.push_back(row);
        }
        det += A1[0][p] * determinant(minor) * (p % 2 == 0 ? 1 : -1);
    }
    return det;
}
