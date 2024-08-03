#pragma once

#include <iostream>
#include <stdexcept>

namespace BST
{


    template <typename T>
    class Binary_Search_Tree
    {

        struct Node;
        // Member types
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
            value_type m_data;
            Node_Pointer m_left;
            Node_Pointer m_right;
            Node(const_reference data) : m_data(data), m_left(nullptr), m_right(nullptr) {}
        };

    public:
        Binary_Search_Tree();
        Binary_Search_Tree(const_reference data);

        const_reference findMin() const;
        reference findMin();
        const_reference findMax() const;
        reference findMax();

        const_Node_pointer find(const_reference data) const;
        Node_Pointer find(const_reference data);
        void insert(const_reference data);
        void remove(const_reference data);

        // traversals
        void preOrderTraversal() const;
        void inOrderTraversal() const;
        void postOrderTraversal() const;

        // Getters for successor and predecessor
        int getSuccessor(const_reference val) const;
        int getPredecessor(const_reference val) const;

    private: // helper functions
        const_reference findHelper(Node_Pointer node, const_reference data) const;
        Node_Pointer insertHelper(Node_Pointer node, const_reference data);
        Node_Pointer removeHelper(Node_Pointer node, const_reference data);

        const_reference findMinHelper(const_Node_pointer node) const;
        reference findMinHelper(Node_Pointer node);
        const_reference findMaxHelper(const_Node_pointer node) const;
        reference findMaxHelper(Node_Pointer node);

        void preOrderHelper(Node_Pointer node) const;
        void inOrderHelper(Node_Pointer node) const;
        void postOrderHelper(Node_Pointer node) const;

    private:
        Node_Pointer root;
    };

}

#include "BST.hpp"
