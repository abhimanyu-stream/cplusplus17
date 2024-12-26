#include <iostream>

// Template function for multiplication
template <typename T>
T multiply(T a, T b)
{
    T result = 0; // Initialize result

    while (b > 0) // Iterate until b becomes 0
    {
        // Check if the least significant bit of b is 1
        if (b & 1)
        {
            result += a; // Add the current value of a to result
        }

        a = a << 1; // Left shift a (double the value of a)
        b = b >> 1; // Right shift b (halve the value of b)
    }

    return result; // Return the final product
}

int findMultiplyTwoNumbers(int a, int b)
{

    int result = 0;

    while (b > 0)
    {

        if (b & 1) // Check if the least significant bit (LSB) of b is 1
        {

            result += a; // Add the current value of a to result if LSB of b is 1
        }
        a = a << 1; // Left shift a by 1 bit (equivalent to multiplying a by 2) i.e  2 to the power 1, 2 to the power 2...
        b = b >> 1; // Right shift b by 1 bit (equivalent to dividing b by 2 and discarding the LSB)
    }
    return result;
}

int main()
{
    int resultRecieved = findMultiplyTwoNumbers(5, 6);
    std::cout << resultRecieved;

    return 0;
}
/**
Explanation:
Result Variable: result is initialized to 0, and it will hold the final result of the multiplication.

Loop Until b Becomes 0:

The loop runs until b becomes 0.
If the least significant bit (LSB) of b is 1, add the value of a to the result (this corresponds to multiplying by 1).
Left Shift a (Doubling):

After each iteration, shift a left by one (a <<= 1). This is equivalent to multiplying a by 2.
Right Shift b (Halving):

After each iteration, shift b right by one (b >>= 1). This is equivalent to dividing b by 2.
Repeat: The process continues, effectively multiplying a by powers of 2 and checking which bits of b are 1 to add the corresponding multiples of a.

Example Walkthrough (for a = 6, b = 99):
Input:
a = 6 (binary 0000000000000110)
b = 99 (binary 0000000001100011)
Iteration 1:
b (binary) is 99, which is 01100011 (LSB = 1).
Add a to result: result = result + a = 0 + 6 = 6.
Left shift a: a = 6 << 1 = 12.
Right shift b: b = 99 >> 1 = 49.
Iteration 2:
b (binary) is 49, which is 110001 (LSB = 1).
Add a to result: result = result + a = 6 + 12 = 18.
Left shift a: a = 12 << 1 = 24.
Right shift b: b = 49 >> 1 = 24.
Iteration 3:
b (binary) is 24, which is 11000 (LSB = 0).
No addition to result.
Left shift a: a = 24 << 1 = 48.
Right shift b: b = 24 >> 1 = 12.
Iteration 4:
b (binary) is 12, which is 1100 (LSB = 0).
No addition to result.
Left shift a: a = 48 << 1 = 96.
Right shift b: b = 12 >> 1 = 6.
Iteration 5:
b (binary) is 6, which is 110 (LSB = 0).
No addition to result.
Left shift a: a = 96 << 1 = 192.
Right shift b: b = 6 >> 1 = 3.
Iteration 6:
b (binary) is 3, which is 11 (LSB = 1).
Add a to result: result = result + a = 18 + 192 = 210.
Left shift a: a = 192 << 1 = 384.
Right shift b: b = 3 >> 1 = 1.
Iteration 7:
b (binary) is 1, which is 1 (LSB = 1).
Add a to result: result = result + a = 210 + 384 = 594.
Left shift a: a = 384 << 1 = 768.
Right shift b: b = 1 >> 1 = 0.
Loop terminates since b == 0.
Final Result:

The multiplication of 6 and 99 is 594.
Output:
yaml
Copy code
Enter two integers: 6 99
The multiplication of 6 and 99 is: 594
Conclusion:
The program multiplies two integers using bitwise operations by simulating the multiplication process through shifting and adding based on the bits of b. The left shift operation effectively doubles a, while the right shift operation halves b, allowing the program to multiply without using the multiplication operator (*).

*/