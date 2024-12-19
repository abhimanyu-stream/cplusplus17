#include <iostream>
#include "Triangle.h"

Triangle::Triangle() : rows(0) {}                          // Default constructor
Triangle::Triangle(int numberOfRow) : rows(numberOfRow) {} // Parameterized constructor
Triangle::~Triangle() {}                                   // Destructor

void Triangle::drawTriangle(int numberOfRow)
{
    for (int i = 1; i <= numberOfRow; i++)
    {
        // Print spaces for alignment
        for (int j = 0; j < numberOfRow - i; j++)
        {
            std::cout << j;
        }

        // Print stars for the current row
        for (int k = 0; k < (2 * i - 1); k++)
        {
            std::cout << "*";
        }

        std::cout << std::endl; // Move to the next line after each row
    }
}
