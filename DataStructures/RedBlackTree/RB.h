#pragma once 

#include <iostream>
#include <cstddef>
#include <queue>
namespace RB {
    enum Color { RED, BLACK };

    struct Node {
    
        using Node_Pointer = Node*; 
        using size_type = std::size_t;
        size_type val;
        Color color;
        Node_Pointer parent;
        Node_Pointer left;
        Node_Pointer right;

        Node() : val(0), color(BLACK), parent(nullptr), left(nullptr), right(nullptr) {}

        Node(const size_type& k) : val(k), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
    };

template <typename T>
class RBTree {
public:
    using value_type = T; 
    using Node_Pointer = Node*; 
    using reference = value_type&;
    using pointer = value_type*; 
    using const_reference = const value_type &;
    using const_pointer = const value_type *;
    using size_type = std::size_t;
    using const_Node_Pointer = const Node_Pointer *;
    
public:
    RBTree();
    RBTree(const_reference val);
    ~RBTree();

    void inOrderTraversal();

    void levelOrder();

    Node_Pointer insert(size_type val);
    void remove(size_type val);
    Node_Pointer search(size_type val);

private:
    Node_Pointer root;
    Node_Pointer NIL; 
   
    void levelOrderHelper(Node_Pointer node);
  
    void inOrderHelper(Node_Pointer node);

    void removeFixUP(Node_Pointer node);
   
    Node_Pointer insertFixUP(Node_Pointer node);
  
    void Transplant(Node_Pointer u, Node_Pointer v);

    void deleteNodeHelper(Node_Pointer node, size_type val);
  
    Node_Pointer searchTreeHelper(Node_Pointer node, size_type val);
   
    Node_Pointer findMin(Node_Pointer node);
   
    Node_Pointer findMax(Node_Pointer node);
 
    void leftRotate(Node_Pointer node);
    
    void rightRotate(Node_Pointer node);
 
    void clear(Node_Pointer node) noexcept;

    Node_Pointer insertNodeHelper(Node_Pointer node , size_type val);
    
};

}

#include "RB.hpp"