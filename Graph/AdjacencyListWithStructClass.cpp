#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

// Struct to represent each Vertex
struct Vertex
{
    Vertex(int v, std::set<int> &a) : vertex_number(v), adjacents(a) {}
    int vertex_number;       // Vertex number (ID)
    std::set<int> adjacents; // Set of adjacent vertices (adjacency list)
};

// Class to represent the Graph
class Graph
{
public:
    // Constructor that accepts a vector of Vertex objects
    Graph(std::vector<Vertex> &v) : v_(v) {}

    // Method to add an edge between two vertices
    void AddEdge(int u, int v);

    // Method to print the adjacency list of the graph
    void PrintGraph();

    // Method to check if the graph has an Eulerian Path
    bool IsEulerianPath();

private:
    std::vector<Vertex> v_; // Vector of vertices
};

// Add an edge between two vertices u and v
void Graph::AddEdge(int u, int v)
{
    // Add v to u's adjacency list
    v_[u].adjacents.insert(v);
    // Add u to v's adjacency list (since it's an undirected graph)
    v_[v].adjacents.insert(u);
}

// Print the adjacency list of the graph
void Graph::PrintGraph()
{
    for (const auto &vertex : v_)
    {
        std::cout << "Vertex " << vertex.vertex_number << " has edges to: ";
        for (const auto &adj : vertex.adjacents)
        {
            std::cout << adj << " ";
        }
        std::cout << std::endl;
    }
}

// Check if the graph has an Eulerian Path
bool Graph::IsEulerianPath()
{
    int oddDegreeCount = 0;

    // Iterate over each vertex to count how many have an odd degree
    for (const auto &vertex : v_)
    {
        if (vertex.adjacents.size() % 2 != 0)
        {
            oddDegreeCount++;
        }
    }

    // Eulerian Path exists if there are exactly 0 or 2 vertices with odd degree
    return (oddDegreeCount == 0 || oddDegreeCount == 2);
}

int main()
{
    // Create vertices
    std::set<int> adj0 = {1, 2};
    std::set<int> adj1 = {0, 2, 3, 4};
    std::set<int> adj2 = {0, 1, 3};
    std::set<int> adj3 = {1, 2, 4};
    std::set<int> adj4 = {1, 3};

    std::vector<Vertex> vertices = {
        Vertex(0, adj0),
        Vertex(1, adj1),
        Vertex(2, adj2),
        Vertex(3, adj3),
        Vertex(4, adj4)};

    // Create the graph with the vertex list
    Graph g(vertices);

    // Print the adjacency list
    std::cout << "Graph adjacency list:" << std::endl;
    g.PrintGraph();

    // Check if the graph has an Eulerian Path
    if (g.IsEulerianPath())
    {
        std::cout << "The graph has an Eulerian Path." << std::endl;
    }
    else
    {
        std::cout << "The graph does NOT have an Eulerian Path." << std::endl;
    }

    return 0;
}
