#include "graph.h"

namespace DataStructures {
    template <typename T>
    WeightedGraph<T>::WeightedGraph(size_type n)
        : adjList{n}
    {}

    template <typename T>
    void WeightedGraph<T>::addEdge(size_type u , size_type v , double weight)
    {
        if (u >= adjList.size() || v >= adjList.size())
        {
            throw std::runtime_error("Out of range ");
        }

        adjList[u].emplace_back(v, weight);
        // adjList[v].emplace_back(u , weight); // Directed Weight_Graph 
    }

    template <typename T>
    void WeightedGraph<T>::DFS_REC(size_type start) const
    {
        std::vector<bool> visited(adjList.size() , false);
        dfsRECHelper(start , visited);
    }

    template <typename T>
    void WeightedGraph<T>::dfsRECHelper(size_type start , std::vector<bool>& visited) const
    {
        std::cout << start << std::endl; 
        visited[start] = true; 
        for (const auto& [vertex , weight] : adjList[start])
        {
            if (!visited[vertex])
            {
                dfsRECHelper(vertex , visited);
            }
        }
    }

    template <typename T>
    void WeightedGraph<T>::BFS(size_type start) const
    {
        std::queue<size_t> q;
        std::vector<bool> visited(adjList.size() , false);
        q.push(start);
        visited[start] = true; 
        bfsHelper(q , visited);
    }

    template <typename T>
    void WeightedGraph<T>::bfsHelper(std::queue<size_t>& q, std::vector<bool>& visited) const
    {
        while (!q.empty())
        {
            size_t val = q.front(); 
            q.pop(); 
            std::cout << val << std::endl; 
            for (const auto& [vertex , weight] : adjList[val])
            {
                if (!visited[vertex])
                {
                    q.push(vertex);
                    visited[vertex] = true; 
                }
            }
        }
        
    }

    template <typename T>
    std::vector<typename WeightedGraph<T>::value_type> WeightedGraph<T>::getShortestPath(size_type u , size_type v) const
    {
        std::vector<bool> visited(adjList.size(), false);
        std::queue<value_type> q;
        q.push(u);
        std::vector<value_type> parent(adjList.size(), -1);
        visited[u] = true;

        while (!q.empty()) {
            value_type current = q.front();
            q.pop();

            if (current == v) {
                std::vector<T> path;
                for (auto at = v; at != -1; at = parent[at]) {
                    path.push_back(at);
                }
                std::reverse(path.begin(), path.end());
                return path;
            }

            for (const auto& [neighbor, weight] : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }
            }
        }
        return {};
    }

    template <typename T>
    WeightedGraph<T> WeightedGraph<T>::Transpose() const 
    {
        WeightedGraph<T> transpose_(adjList.size());

        for (size_type node = 0; node < adjList.size(); ++node)
        {
            for (auto& [neighbor, weight] : adjList[node])
            {
                transpose_.addEdge(neighbor , node);
            }
        }
        return transpose_;
    }

    template <typename T>
    bool WeightedGraph<T>::isCycledUndirected() const 
    {
        std::vector<bool> visited(adjList.size() , false);
        for (int i {}; i < adjList.size(); ++i)
        {
            if (!visited[i])
            {
                if (dfsCycledUndirected(i , visited , -1))
                {
                    return true; 
                }
            }
        }
        return false; 
    }

    template <typename T>
    bool WeightedGraph<T>::dfsCycledUndirected(value_type start , std::vector<bool>& visited , value_type parent) const 
    {
        visited[start] = true; 
        for (const auto& [vertex , weight] :adjList[start])
        {
            if (!visited[vertex])
            {
                if (dfsCycledUndirected(vertex , visited , start))
                {
                    return true; 
                }
            }
            else if (vertex != parent)
            {
                return true; 
            }
        }
        return false; 
    }  

    template <typename T>
    bool WeightedGraph<T>::isCycledDirected() const 
    {
        std::vector<bool> recStack(adjList.size() , false);
        std::vector<bool> visited(adjList.size() , false);
        for (int i {}; i < adjList.size(); ++i)
        {
            if (!visited[i])
            {
                if (dfsCycledDirected(i, visited , recStack))
                {
                    return true; 
                }
            }

        }
        return false; 
    }

    template <typename T>
    bool WeightedGraph<T>::dfsCycledDirected(value_type start , std::vector<bool>& visited,  std::vector<bool>& recStack) const 
    {
        visited[start] = true; 
        recStack[start] = true; 
        for (const auto& [vertex , weight] : adjList[start])
        {
            if (!visited[vertex])
            {
                if (dfsCycledDirected(vertex , visited , recStack))
                {
                    return true; 
                }

            } 
            else if (recStack[vertex])
            {
                return true; 
            }
        }
        recStack[start] = false; 
        return false;
    }


    



}