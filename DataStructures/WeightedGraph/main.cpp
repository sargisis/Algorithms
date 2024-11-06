#include "graph.h"
#include <future>

using namespace DataStructures;

int main(void)
{
    WeightedGraph<int> a(6);

    a.addEdge(0, 1, 2.5);
    a.addEdge(0, 2, 53.3);
    a.addEdge(2, 1, 5.5);
    a.addEdge(3, 2, 2.2);
    a.addEdge(1, 2, 3.3);
    a.addEdge(0, 3, 3.3);

    
    if (a.isCycledUndirected())
    {
        std::cout << "Yes " << std::endl; 
    }
    else 
    {
        std::cout << "No " << std::endl; 
    }

}