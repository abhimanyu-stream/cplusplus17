#include <iostream>
#include <vector>
#include <cstring> // For memset

using namespace std;

// Function to solve the Knapsack problem using recursion with memoization
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n, vector<vector<int>>& memo) {
    // Base case: no items left or no capacity left
    if (n == 0 || capacity == 0) {
        return 0;
    }

    // If the value is already computed, return it
    if (memo[n][capacity] != -1) {
        return memo[n][capacity];
    }

    // If the weight of the nth item is more than the capacity, skip it
    if (weights[n - 1] > capacity) {
        memo[n][capacity] = knapsack(capacity, weights, values, n - 1, memo);
        return memo[n][capacity];
    }

    // Recursive cases: either include or exclude the nth item
    // 1. Include the nth item
    int include = values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1, memo);
    // 2. Exclude the nth item
    int exclude = knapsack(capacity, weights, values, n - 1, memo);

    // Store the result in memo and return the maximum of the two cases
    memo[n][capacity] = max(include, exclude);
    return memo[n][capacity];
}

int main() {
    // Example input
    vector<int> values = {60, 100, 120}; // Values of items
    vector<int> weights = {10, 20, 30};  // Weights of items
    int capacity = 50;                   // Capacity of the knapsack
    int n = values.size();               // Number of items

    // Initialize memoization table with -1
    vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1));

    // Solve the Knapsack problem
    int maxValue = knapsack(capacity, weights, values, n, memo);

    // Output the result
    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
/**
 * 
 * Here is the 0/1 Knapsack Problem implementation in C++ using recursion with memoization:
 * Explanation
Memoization Table:

The memo table is a 2D vector where memo[n][capacity] stores the maximum value obtainable with n items and a knapsack of capacity.
Base Case:

When no items are left (n == 0) or the knapsack has no capacity (capacity == 0), the value is 0.
Recursive Case:

If the result for a subproblem is already computed (memo[n][capacity] != -1), return it.
Otherwise:
Skip the current item if its weight exceeds the remaining capacity.
Otherwise, compute the maximum value between:
Including the current item.
Excluding the current item.
Store the result in the memo table for future use.
Parameters:

capacity: Remaining capacity of the knapsack.
weights: Vector of item weights.
values: Vector of item values.
n: Number of items left.
memo: Memoization table.
Input Example
cpp
Copy code
Values: {60, 100, 120}
Weights: {10, 20, 30}
Capacity: 50
Output
yaml
Copy code
Maximum value in Knapsack: 220
Complexity
Time Complexity: 
𝑂
(
𝑛
×
capacity
)
O(n×capacity), where n is the number of items and capacity is the knapsack's capacity. Memoization avoids redundant calculations.
Space Complexity: 
𝑂
(
𝑛
×
capacity
)
O(n×capacity), for the memo table, and 
𝑂
(
𝑛
)
O(n) for the recursion stack.
This implementation is both time-efficient and space-efficient for solving the 0/1 Knapsack problem with recursion. Let me know if you'd like further explanations or enhancements!

 */