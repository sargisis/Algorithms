#pragma once 

#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#include <cstddef>
#include <stdexcept>
   
namespace DataStructures {

template <typename T>
class Graph
{   
public:
    using value_type = T;
    using pointer = value_type*; 
    using reference = value_type&;
    using const_reference = const value_type&;
    using const_pointer = const value_type*;
    using size_type = std::size_t; 

public:
    Graph(size_type n);
    void addEdge(size_type u, size_type v);
    void addVertex();
    void DFS(size_type start) const;
    void DFS_REC(size_type start) const; 
    void BFS(size_type start) const; 
    void BFS_REC(size_type start) const; 
    void print() const;
    std::vector<value_type> getShortPathInUnweigedGraph(T u, T v) ;
    Graph<T> Transpose() const; 
    bool isCycledUndirected() const;
    bool isCycledDirected() const;
    void topSort() const;
    value_type getCountNthLevel(value_type start, value_type level) const;
    value_type getCountNthLevelWithDFS(value_type start, value_type level) const;
    std::vector<std::vector<T>> getAllPossiblePaths(value_type src, value_type dest) const;
    std::vector<value_type> Kahn() const;
    std::vector<std::vector<T>> Kosarajou();
    std::vector<std::vector<T>> TarjansAlgorithm() const;
private:
    std::vector<std::vector<T>> adjList; 
    
    void dfsRECHelper(size_type start, std::vector<bool>& visited) const;
    void dfsITERHelper(size_type start , std::vector<bool>& visited) const; 
    void bfsHelper(size_type start , std::vector<bool>& visited) const; 
    void bfsRECHelper(std::queue<T>& q , std::vector<bool>& visited) const;
    void dfsHelperForLevelCount(size_type value, std::vector<bool>& visited , value_type current_level , value_type target_level , reference count) const;
    bool dfsCycledUndirected(value_type start, std::vector<bool>& visit, value_type parent) const;
    bool dfsCycledDirected(value_type start, std::vector<bool>& visit, std::vector<bool>& recStack) const;
    void dfsTopSort(value_type start, std::vector<bool>& visit, std::stack<int>& st) const;
    void dfsAllPaths(value_type src, value_type dest, std::vector<value_type>& tmp, std::vector<std::vector<value_type>>& res, std::vector<bool>& visit) const;
    void fillinorder(value_type src, std::vector<bool>& visit, std::stack<int>& st) const;
    void dfsKosarajou(value_type src, std::vector<bool>& visit, std::vector<int>& vec) const;
    void TarjanHelper(value_type src, std::vector<int>& ids, std::vector<int>& lowlink, std::stack<int>& st, std::vector<bool>& onStack, std::vector<std::vector<int>>& SCCs) const;

};

}

#include "graph.hpp"