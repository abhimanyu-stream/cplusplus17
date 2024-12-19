#include <iostream>
#include "Triangle.h"

int main()
{
    std::cout << "Triangle Program.." << std::endl;

    int rows = 5;
    Triangle *t = new Triangle();

    t->drawTriangle(rows);

    delete t; // Properly delete the allocated memory
    return 0;
}
