/**
 *
 * 2D Array


 Directed:
 M[i,j] = 1 if(i,j) blongs E
 M[i,j] = 0 otherwise

 For unDirected :
 edges are bidirectional
 M[i,j] = M[j,i] = 1 if (i, j) belong E
 M[i,j] = otherwise
 symetricail graph


 // implementation

 class  Graph{

public:

Graph(std::vector<std::vector<int>> &adjacency) : adjacency_(adjacency){}

bool IsEulerWalkable();
std::vector<std::vector<int>> adjacency_;




 };

 bool Graph::IsEulerWakable(){

 std::vector<int> degrees(adjacency_.size());
 for(int i = 0; i < adjacency_.size(); i++){
 for(int j = 0; j< adajency_size(); j++){
 if(adjacency_[i][j] == 1) {
 degrees[i]++;
 }

 }

 }



 }

 int main(){
 std::vector<std::vector<int>> adjacency = {{0,1,1,0,0},
 {1,0,1,1,1},
 {1,1,0,1,0},
 {0,1,1,0,1},
 {0,1,0,1,0}


 };
 Graph g(adjacency);



 }

 */
#include <iostream>
#include <vector>

class Graph
{
public:
    // Constructor accepts the adjacency matrix by reference
    Graph(const std::vector<std::vector<int>> &adjacency) : adjacency_(adjacency) {}

    // Method to check if the graph has an Eulerian Path
    bool IsEulerianPath();
    int CountOddDegreeNodes();

private:
    std::vector<std::vector<int>> adjacency_; // Adjacency matrix
};

// Method to check if the graph has an Eulerian Path
bool Graph::IsEulerianPath()
{
    std::vector<int> degrees(adjacency_.size(), 0);

    // Calculate the degree for each vertex
    for (int i = 0; i < adjacency_.size(); i++)
    {
        for (int j = 0; j < adjacency_.size(); j++)
        {
            if (adjacency_[i][j] == 1)
            {
                degrees[i]++;
            }
        }
    }

    // Count how many vertices have an odd degree
    int countOdds = 0;
    for (int d : degrees)
    {
        if (d % 2 == 1)
        {
            countOdds++;
        }
    }

    // An Eulerian Path exists if there are 0 or exactly 2 vertices with odd degree
    return (countOdds == 0 || countOdds == 2);
}

// Function to count nodes with odd degrees in an undirected graph
// Method to count nodes with odd degrees in the graph
int Graph::CountOddDegreeNodes()
{
    int oddCount = 0;

    // Calculate the degree for each vertex
    for (int i = 0; i < adjacency_.size(); i++)
    {
        int degree = 0;
        for (int j = 0; j < adjacency_.size(); j++)
        {
            if (adjacency_[i][j] == 1)
            {
                degree++;
            }
        }
        if (degree % 2 != 0)
        {
            oddCount++;
        }
    }

    return oddCount;
}
int main()
{
    // Example graph (Adjacency Matrix)
    std::vector<std::vector<int>> adjacency = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}};

    // Create Graph object
    Graph g(adjacency);

    // Check if the graph has an Eulerian Path
    if (g.IsEulerianPath())
    {
        std::cout << "The graph has an Eulerian Path." << std::endl;
    }
    else
    {
        std::cout << "The graph does NOT have an Eulerian Path." << std::endl;
    }

   // Count nodes with odd degree
    int oddDegreeCount = g.CountOddDegreeNodes();
    std::cout << "Number of nodes with odd degree: " << oddDegreeCount << std::endl;

    return 0;
}
