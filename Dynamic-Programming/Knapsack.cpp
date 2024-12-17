/*knapsack.cpp*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive function for the Knapsack problem
int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    // Base case: no items left or no capacity left
    if (n == 0 || capacity == 0)
        return 0;

    // If the weight of the nth item is more than the current capacity, skip it
    if (weights[n - 1] > capacity)
        return knapsack(capacity, weights, values, n - 1);

    // Recursive cases: either include or exclude the nth item
    // 1. Include the nth item and subtract its weight from capacity
    // 2. Exclude the nth item
    int include = values[n - 1] + knapsack(capacity - weights[n - 1], weights, values, n - 1);
    int exclude = knapsack(capacity, weights, values, n - 1);

    // Return the maximum of including or excluding the nth item
    return max(include, exclude);
}

int main() {
    // Example input
    vector<int> values = {60, 100, 120};  // Values of items
    vector<int> weights = {10, 20, 30};  // Weights of items
    int capacity = 50;  // Capacity of the knapsack
    int n = values.size();  // Number of items

    cout << "Maximum value in Knapsack: " << knapsack(capacity, weights, values, n) << endl;

    return 0;
}
