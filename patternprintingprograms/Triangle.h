#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
public:
    int rows;

    Triangle();                // Default constructor
    Triangle(int numberOfRow); // Parameterized constructor
    ~Triangle();               // Destructor

    void drawTriangle(int); // Method to draw the triangle
};

#endif
//interface like java