#include "graph.h"




using namespace DataStructures;


int main()
{
    Graph<int> graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(2,1);
    graph.addEdge(2,3);
    graph.addEdge(1,3);
    graph.addEdge(3,4);

    std::vector<int> s = graph.Kahn();

    for (auto& e : s)
    {
        std::cout << e << std::endl; 
    } 


    return 0; 

}