/**bits-addition.cpp
add two numbers using bitwise operators


*/

#include <iostream>

int addTwoNumbersBitWiseB(int a, int b)
{

    while (b != 0)
    {

        int carry = a & b; // carry
        a = a ^ b;         // sum
        b = carry << 1;    // carry is shifted by one
    }
    return a;
}

int main()
{
    int x = 6;
    int y = 99;
    int result = addTwoNumbersBitWiseB(x, y);
    std::cout << "the adition of two numbers is B " << result << std::endl;

    return 0;
}
