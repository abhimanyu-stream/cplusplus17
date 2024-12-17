/** V:Set/List/Vector of Vertices
 * V={0,1,2,3}
 * std::vector OR std::list OR std::set
 *
 *
 * E: Set/List?Vector of pairs
 * E={(0,1), (1,2),(2,3),(3,0)}
 * for E =>  vector/list/set
 *
 * for (3,0) => pair/vector/list/set
 *
 *
 * class Graph{
 *
 * private:
 *
 * public:
 * Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e) : v_(v), e_(e {}
 *
 * bool IsEulerWalkable();
 * std::vector<int> v_;
 * std::vector<std::pair<int, int>> e_;
 *
 * };
 *
 *
 * bool Graph:: IsEulerWalkable(){
 *
 *
 * //is the count of odd degree vertices is 0 or 2?
 * iterator through edges
 *
 * std::vector<int> degrees(v_.size());
 *
 * for(auto e: e_){
 * degrees[e.first]++;
 * degress[e.second]++;
 *
 * }
 *
 * int countOdds = 0;
 * for(auto d: degrees){
 * if(d % 2 == 1){
 * countOdds++;
 *
 * }
 *
 * }
 *return (countOdd ==  0 || countOdds == 2);
 * }
 *
 *
 * int main(){
 *
 *
 *
 * std::vector<int> v = {0,1,2,3};// uinform initialize
 * std::vector<std::pair<int, int>> e = {{01}, {1,2},{2,3},{3,0}};
 *
 * Graph g(v, e);
 *
 * std::cout<< g.IsEulerWalable()<<std::endl;
 *
 *
 * }
 */
#include <iostream>
#include <vector>

class Graph
{
private:
    std::vector<int> v_;
    std::vector<std::pair<int, int>> e_;

public:
    Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e) : v_(v), e_(e) {}

    bool IsEulerWalkable();
};

bool Graph::IsEulerWalkable()
{
    // Check if the count of odd degree vertices is 0 or 2
    std::vector<int> degrees(v_.size(), 0); // Initialize degrees vector to 0
                                            /**
                                             *
                                             * Additional Notes
                                            The method IsEulerWalkable() checks if the graph has an Eulerian path or circuit:
                                            If countOdds == 0: The graph has an Eulerian circuit.
                                            If countOdds == 2: The graph has an Eulerian path.
                                            If countOdds > 2: Neither an Eulerian path nor a circuit is possible.
                                        
                                             */
    for (auto e : e_)
    {
        degrees[e.first]++;
        degrees[e.second]++;
    }

    int countOdds = 0;
    for (auto d : degrees)
    {
        if (d % 2 == 1)
        {
            countOdds++;
        }
    }

    return (countOdds == 0 || countOdds == 2);
}

int main()
{
    // Uniform initialization of vertices and edges
    std::vector<int> v = {0, 1, 2, 3};
    std::vector<std::pair<int, int>> e = {{0, 1}, {1, 2}, {2, 3}, {3, 0}}; // Correct edge format

    Graph g(v, e);
    std::cout << (g.IsEulerWalkable() ? "Eulerian path or cycle is possible" : "Eulerian path or cycle is not possible") << std::endl;

    return 0;
}
