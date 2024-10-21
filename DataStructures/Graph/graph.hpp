#pragma once
#include "graph.h"

namespace DataStructures 
{
    template <typename T>
    Graph<T>::Graph(size_type n) : adjList{n}
    {}

    template <typename T>
    void Graph<T>::addEdge(size_type u , size_type v)
    {   
        adjList[u].push_back(v); 
        // adjList[v].push_back(u); // comment this line for a directed graph
    }

    template <typename T>
    void Graph<T>::print() const 
    {
         for (size_type i {0}; i < adjList.size(); ++i) 
        {
            std::cout << i << ": ";
            for (const auto& neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    template <typename T>
    void Graph<T>::addVertex()
    {
        adjList.push_back(std::vector<T>());
    }


    template <typename T>
    void Graph<T>::DFS_REC(size_type start) const 
    {
        std::vector<bool> visited(adjList.size() , false);
        dfsRECHelper(start , visited);
    }

    template <typename T>
    void Graph<T>::dfsRECHelper(size_type start , std::vector<bool>& visited) const 
    {
        visited[start] = true; 
        std::cout << start << std::endl; 
        for (const auto& neighbor : adjList[start])
        {
            if (!visited[neighbor])
            {
                dfsRECHelper(neighbor , visited);
            }
        }
    }

    template <typename T>
    void Graph<T>::DFS(size_type start) const
    {
        std::vector<bool> visit(adjList.size() , false);
        dfsITERHelper(start , visit);
    }

    template <typename T>
    void Graph<T>::BFS(size_type start) const
    {
        std::vector<bool> visit(adjList.size() , false);
        for (int i = 0; i < adjList.size(); ++i)
        {
            if (!visit[i])
            {
               bfsHelper(i , visit);
            }
        }
    }

    template <typename T>
    void Graph<T>::bfsHelper(size_type start , std::vector<bool>& visited) const
    {
        std::queue<T> q;
        q.push(start);
        visited[start] = true; 
        while (!q.empty())
        {
            value_type node = q.front();
            q.pop();
            std::cout << node << std::endl; 
            for (const auto& neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    template <typename T>
    void Graph<T>::dfsITERHelper(size_type start , std::vector<bool>& visited) const
    {
        std::stack<T> st;
        st.push(start);
        visited[start] = true; 
        while(!st.empty())
        {
            size_type val = st.top();
            std::cout << val << " " << std::endl; 
            st.pop();
            for (auto& neighbor : adjList[val])
            {
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }


    template <typename T>
    void Graph<T>::BFS_REC(size_type start) const
    {
        std::vector<bool> visit(adjList.size() , false);
        std::queue<T> q;
        q.push(start);
        visit[start] = true; 
        bfsRECHelper(q, visit);
    } 

    template <typename T>
    void Graph<T>::bfsRECHelper(std::queue<T>& q, std::vector<bool>& visited) const
    {
        if (q.empty())
        {
            return;
        }
        auto val = q.front();
        q.pop();
        std::cout << val << std::endl; 
        for (const auto& neighbor : adjList[val])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true; 
            }
        }
        bfsRECHelper(q,visited);
    }

    template <typename T>
    Graph<T>::value_type Graph<T>::getCountNthLevelWithDFS(value_type start , value_type level) const 
    {
        if (start >= adjList.size())
        {
            throw std::out_of_range("Start nodes is out of bound");
        }
        int count = 0; 
        std::vector<bool> visit(adjList.size() , false);

        dfsHelperForLevelCount(start , visit , 0, level , count);
        return count; 
    }

    template <typename T>
    void Graph<T>::dfsHelperForLevelCount(size_type start , std::vector<bool>& visited, value_type current_level , value_type target_level,  reference count) const
    {
        visited[start] = true; 

        if (current_level == target_level)
        {
            count++;
        }
        if (current_level > target_level)
        {
            return; 
        }
        for (const auto& neighbor : adjList[start])
        {
            if (!visited[neighbor])
            {
                dfsHelperForLevelCount(start ,visited , current_level + 1  , target_level , count);
            }
        }
    }

    template <typename T>
    Graph<T>::value_type Graph<T>::getCountNthLevel(value_type start , value_type level) const 
    {
        std::vector<bool> visit(adjList.size() , false);
        std::queue<value_type> q;
        q.push(start);
        visit[start] = true; 
        while (!q.empty())
        {
            value_type u = q.front();
            q.pop();
            --level;
            for (const auto& neighbor : adjList[u])
            {
                if (!visit[neighbor])
                {
                    q.push(neighbor);
                    visit[neighbor] = true;
                }
            }
            if (level == 0)
            {
                break;
            }
        }
        return q.size();
    }

    template <typename T>
    Graph<T> Graph<T>::Transpose() const
    {
        Graph<T> transpose_(adjList.size());

        for (size_type node = 0; node < adjList.size(); ++node)
        {
            for (auto& neighbor : adjList[node])
            {
                transpose_.addEdge(neighbor , node);
            }
        }
        return transpose_;
    }

    template <typename T>
    std::vector<T> Graph<T>::getShortPathInUnweigedGraph(T u , T v)
    {
        std::vector<bool> visited(adjList.size() , false);
        std::queue<value_type> q;
        q.push(u);
        std::vector<value_type> parent(adjList.size() , -1);
        visited[u] = true; 
        
        while (!q.empty())
        {
            value_type current = q.front();
            q.pop();

            if (current == v)
            {
                std::vector<T> path; 
                for (auto at = v; at != -1; at = parent[at])
                {
                    path.push_back(at);
                }
                std::reverse(path.begin() , path.end());
                return path;
            }

            for (const auto& neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true; 
                    parent[neighbor] = current;
                }
            }
        }  
        return {};
    }

    template <typename T>
    std::vector<std::vector<T>> Graph<T>::getAllPossiblePaths(value_type src , value_type dest) const
    {
        std::vector<bool> visited(adjList.size() , false);
        std::vector<value_type> current;
        std::vector<std::vector<value_type>> all; 
        dfsAllPaths(src, dest , current , all , visited);
        return all;
    }

    template <typename T>
    void Graph<T>::dfsAllPaths(value_type src , value_type dest , std::vector<value_type>& tmp , std::vector<std::vector<value_type>>& res , std::vector<bool>& visited) const
    {
        visited[src] = true; 
        tmp.push_back(src);
        if (src == dest)
        {
            res.push_back(tmp);
        }
        for (const auto& u : adjList[src])
        {
            if (!visited[u])
            {
                dfsAllPaths(u , dest, tmp , res , visited);
            }
        }

        tmp.pop_back();
        visited[src] = false;
    }

    template <typename T>
    bool Graph<T>::isCycledUndirected() const 
    {
        std::vector<bool> visited(adjList.size() , false);
        for (int i {0}; i < adjList.size(); ++i)
        {
            if (!visited[i]) {
              if (dfsCycledUndirected(i , visited , -1)) 
              {
                return true; 
              }
            }
        }
        return false;
    }

    template <typename T>
    bool Graph<T>::dfsCycledUndirected(value_type start , std::vector<bool>& visited , value_type parent) const
    {
        visited[start] = true; 
        for (const auto& neighbor : adjList[start])
        {
            if (!visited[neighbor])
            {
                if (dfsCycledUndirected(neighbor , visited , start)) {
                    return true; 
                }     
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }
        return false; 
    }

    template <typename T>
    bool Graph<T>::isCycledDirected() const 
    {
        std::vector<bool> visited(adjList.size() , false);
        std::vector<bool> recStack(adjList.size() , false);

        for (int i {0}; i < adjList.size(); ++i)
        {
            if (!visited[i])
            {
                if (dfsCycledDirected(i , visited , recStack))
                {
                    return true; 
                }
            }
        }
        return false; 
    }

    template <typename T>
    bool Graph<T>::dfsCycledDirected(value_type start , std::vector<bool>& visit, std::vector<bool>& recStack) const
    {
        visit[start] = true; 
        recStack[start] = true; 
        for (const auto& vertex : adjList[start])
        {
            if (!visit[vertex])
            {
                if (dfsCycledDirected(vertex , visit , recStack))
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

    template <typename T>
    void Graph<T>::topSort() const 
    {
        std::vector<bool> visited(adjList.size(), false);
        std::stack<int> st;
        for (int i {0}; i < adjList.size(); ++i)
        {
            if (!visited[i])
            {
                dfsTopSort(i, visited, st);
            }
        }
    }    

    template <typename T> 
    void Graph<T>::dfsTopSort(value_type start , std::vector<bool>& visited , std::stack<int>& st) const 
    {
        visited[start] = true; 
        for (auto& vertex : adjList[start])
        {
            if (!visited[vertex])
            {
                dfsTopSort(vertex , visited , st);
            }
        }
        st.push(start);

        while (!st.empty())
        {
            std::cout << st.top() << " ";
            st.pop();
        }
        std::cout << std::endl;
    }

    template <typename T>
    std::vector<typename Graph<T>::value_type> Graph<T>::Kahn() const 
    {
        std::vector<int> inDegree(adjList.size(), 0);
        for (int u {0}; u < adjList.size(); ++u)
        {
            for (auto& vertex : adjList[u])
            {
                inDegree[vertex]++;
            }
        }
        std::queue<value_type> q; 
        for (int u{0}; u < adjList.size(); ++u)
        {    
            if (inDegree[u] == 0)
            {
                q.push(u);
            }
        }

        std::vector<value_type> result; 
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            result.push_back(node);

            for (auto& vertex : adjList[node])
            {
                inDegree[vertex]--;
            
                if (inDegree[vertex] == 0)
                {
                    q.push(vertex);
                }
            }
        }

        if (result.size() != adjList.size())
        {
            throw std::out_of_range("Graph is Cycled");   
            return {};
        }

        return result; 
    }
}






