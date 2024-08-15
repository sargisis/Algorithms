#pragma once


#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstddef>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
namespace AVL {

template <typename T> 
class AVL_Tree 
{          
    struct Node; 
public:
        using Node_Pointer = Node *;
        using value_type = T;
        using reference = value_type &;
        using pointer = value_type *;
        using const_reference = const value_type &;
        using const_pointer = const value_type *;
        using size_type = std::size_t;
        using const_Node_pointer = const Node_Pointer *;
private:

    struct Node
    {
    public: 
        value_type val;
        Node_Pointer left;
        Node_Pointer right;
        Node(const_reference data) : val(data), left(nullptr), right(nullptr) {}
    };
public:

        AVL_Tree();
        ~AVL_Tree() noexcept;
        AVL_Tree(const_reference data); 

        const_reference findMin() const;
        const_reference findMax() const;

        size_type getHeight() const; 

        size_type updateHeight(Node_Pointer node) const; 

        size_type find(Node_Pointer node , const_reference data) const;

        void insert(const_reference data);
        void remove(const_reference data);

        size_type getBalanceFactor(Node_Pointer node) const; 

        bool is_empty() const; 
 
        // traversals
       void preOrderTraversal() const;
       void inOrderTraversal() const;
       void postOrderTraversal() const;
       void levelOrderTraversal() const; 

       Node_Pointer leftRotate(); 
       Node_Pointer rightRotate();

        // Getters for successor and predecessor
        int getSuccessor(const_reference val) const;
        int getPredecessor(const_reference val) const;

       bool contains(const_reference val) const;

    private: // helper functions
        Node_Pointer insertHelper(Node_Pointer node, const_reference data);
        Node_Pointer removeHelper(Node_Pointer node, const_reference data);


      Node_Pointer clear(Node_Pointer node);
      reference findMinHelper(Node_Pointer node);
    
      void preOrderHelper(Node_Pointer node) const;
      void inOrderHelper(Node_Pointer node) const;
      void postOrderHelper(Node_Pointer node) const;
      void levelOrderHelper(Node_Pointer node) const; 

      Node_Pointer leftRotateHelper(Node_Pointer node);
      Node_Pointer rightRotateHelper(Node_Pointer node);

    
private:
    Node_Pointer root; 

};
} // namespace AVL

#include "AVL.hpp"