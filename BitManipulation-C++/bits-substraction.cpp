
#include <iostream>

int substractTwoNumbersBitWiseB(int a, int b)
{

    while (b != 0)
    {
        int borrow = (~a) & b;//  
        a = a ^ b;
        b = borrow << 1;
    }

    return a;
}

int main()
{
    int x = 6;
    int y = 99; // 6 - 99 = -93
    int result = substractTwoNumbersBitWiseB(x, y);
    std::cout << "the substract of two numbers is " << result << std::endl;

    return 0;
}