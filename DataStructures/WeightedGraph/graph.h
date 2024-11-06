#pragma once 

#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <cstddef>
#include <stdexcept>
#include <limits>
#include <utility> 

namespace DataStructures {

template <typename T>
class WeightedGraph 
{
public:
    using value_type = T;
    using pointer = value_type*; 
    using reference = value_type&;
    using const_reference = const value_type&;
    using const_pointer = const value_type*;
    using size_type = std::size_t;

public:
    
    WeightedGraph(size_type n);
    
    void addEdge(size_type u, size_type v, double weight);

    void DFS_REC(size_type start) const; 
    void BFS(size_type start) const; 

    std::vector<value_type> getShortestPath(size_type u, size_type v) const;
    WeightedGraph<T> Transpose() const; 
    bool isCycledUndirected() const;
    bool isCycledDirected() const;

private:
    std::vector<std::vector<std::pair<T, double>>> adjList;

    void dfsRECHelper(size_type start, std::vector<bool>& visited) const;
    void bfsHelper(std::queue<size_type>& q , std::vector<bool>& visited) const;
    bool dfsCycledUndirected(value_type start, std::vector<bool>& visit, value_type parent) const;
    bool dfsCycledDirected(value_type start, std::vector<bool>& visit, std::vector<bool>& recStack) const;
};

} 

#include "graph.hpp"
