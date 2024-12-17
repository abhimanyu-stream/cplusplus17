#include <iostream>
#include <vector>
using namespace std;

// Function to count nodes with odd degrees in an undirected graph
int countOddDegreeNodes(const vector<vector<int>> &graph)
{
    int oddCount = 0;

    // Iterate through each node's adjacency list
    for (const auto &neighbors : graph)
    {
        int degree = neighbors.size(); // Degree is the size of the adjacency list for the node
        if (degree % 2 != 0)
        {
            oddCount++;
        }
    }

    return oddCount;
}

int main()
{
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2, 3}, // Node 0 is connected to nodes 1 and 2
        {0, 2},    // Node 1 is connected to nodes 0 and 2
        {0, 1, 3}, // Node 2 is connected to nodes 0, 1, and 3
        {2}        // Node 3 is connected to node 2
    };

    int oddDegreeCount = countOddDegreeNodes(graph);
    cout << "Number of nodes with odd degree: " << oddDegreeCount << endl;

    return 0;
}
/**
 *
 * Additional Notes
The method IsEulerWalkable() checks if the graph has an Eulerian path or circuit:
If countOdds == 0: The graph has an Eulerian circuit.
If countOdds == 2: The graph has an Eulerian path.
If countOdds > 2: Neither an Eulerian path nor a circuit is possible.

 */