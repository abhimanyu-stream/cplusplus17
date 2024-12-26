/*

V: Set/List/Vector of veritces
E: Set/Map/List/Vector of pairs

Vertex  Adjacents
0       {1,2}
1       {0,2,3,4}
2       {0,1,3}
3       {1,2,4}


struct Vertex {
Vertex(int v. std::set<int> &a) : vertex_number(v), adjacents(a){}
int vertex_number;
std::set<int> adjacents;


};

class Graph{
pulbic :
Graph(std::vector<Vectex> &v) : v_(v) {}
std::vector<Vertex> v_;


};
//using map
class Graph{
public:
Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}
std::map<int, std::set<int>> v_;

};

int main(){

Graph g({Vertex(0, {1,2}), Vertex(1, {0,2,3,4}), Vertex(2, {0,1,3}),Vertex(3,{1,2,4})});
std::cout<<g.IsEulerWalkable()<<std<<endl;


//using map
std::map<int, std::set<int>> verices{

{0,{1,2}},
{1, {0,2,3,4}},
{2,{0,1,3}},
{3,{1,2,4}}



};
Graph g(vertices);



}
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Graph
{
public:
    // Constructor accepting adjacency list as a map (using map<int, set<int>>)
    Graph(std::map<int, std::set<int>> vertices) : v_(vertices) {}

    // Function to check if the graph has an Eulerian Path (Eulerian Walk)
    bool IsEulerWalkable();

private:
    std::map<int, std::set<int>> v_; // Adjacency list (map of vertex -> set of adjacent vertices)
};

// Function to check if the graph has an Eulerian Path
bool Graph::IsEulerWalkable()
{
    int oddDegreeCount = 0;

    // Check the degree of each vertex (size of adjacent set)
    for (const auto &vertex : v_)
    {
        int degree = vertex.second.size();
        if (degree % 2 != 0)
        {
            oddDegreeCount++;
        }
    }

    // Eulerian path exists if there are exactly 0 or 2 vertices with odd degree
    return (oddDegreeCount == 0 || oddDegreeCount == 2);
}

int main()
{
    // Example graph (Adjacency list as a map of vertex -> adjacent vertices)
    std::map<int, std::set<int>> vertices = {
        {0, {1, 2}},
        {1, {0, 2, 3, 4}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4}},
        {4, {1, 3}} // Adding the vertex 4
    };

    // Create Graph object
    Graph g(vertices);

    // Check if the graph has an Eulerian Path (Eulerian Walk)
    if (g.IsEulerWalkable())
    {
        std::cout << "The graph has an Eulerian Path." << std::endl;
    }
    else
    {
        std::cout << "The graph does NOT have an Eulerian Path." << std::endl;
    }

    return 0;
}
