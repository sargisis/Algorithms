#pragma once

#include "AVL.h"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <queue> 

namespace AVL {
    template <typename T> 
    AVL_Tree<T>::AVL_Tree() : root{nullptr} {}

    template <typename T>
    AVL_Tree<T>::AVL_Tree(const_reference data) : root{new Node(data)} {}

    template <typename T> 
    AVL_Tree<T>::~AVL_Tree() noexcept { clear(root); }

    template<typename T>
    typename AVL_Tree<T>::Node_Pointer AVL_Tree<T>::clear(Node_Pointer node) 
    {
        if (node != nullptr)
        {
            clear(node->left);
            clear(node->right);
            delete node; 
        }
        return nullptr; 
    } 

    template<typename T>
    typename AVL_Tree<T>::size_type AVL_Tree<T>::find(Node_Pointer node , const_reference data) const 
    {
        if (!node) return -1;
        if (data < node->val)
            return find(node->left, data);
        else if (data > node->val)
            return find(node->right, data);
        else
            return node->val;
    }

    template<typename T>
    typename AVL_Tree<T>::size_type AVL_Tree<T>::getHeight() const 
    {
        if (!root) return 0;
        return updateHeight(root);
    }

    template<typename T>
    typename AVL_Tree<T>::size_type AVL_Tree<T>::updateHeight(Node_Pointer node) const 
    {
        if (!node) return 0;
        size_type leftHeight = updateHeight(node->left);
        size_type rightHeight = updateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    template<typename T>
    void AVL_Tree<T>::inOrderTraversal() const 
    {
       inOrderHelper(root);
    }

    template<typename T>
    void AVL_Tree<T>::levelOrderTraversal() const 
    {
       levelOrderHelper(root);
    }

    template<typename T>
    void AVL_Tree<T>::postOrderTraversal() const 
    {
       postOrderHelper(root);
    }

    template<typename T>
    void AVL_Tree<T>::preOrderTraversal() const 
    {
       preOrderHelper(root);
    }

    
    template<typename T>
    void AVL_Tree<T>::preOrderHelper(Node_Pointer node) const 
    {
        if (node != nullptr)
        {
            std::cout << node->val << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }
    
    template<typename T>
    void AVL_Tree<T>::postOrderHelper(Node_Pointer node) const 
    {
        if (node != nullptr)
        {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            std::cout << node->val << " ";
        }
    }

    template<typename T>
    void AVL_Tree<T>::inOrderHelper(Node_Pointer node) const 
    {
        if (node != nullptr)
        {
            inOrderHelper(node->left);
            std::cout << node->val << " ";
            inOrderHelper(node->right);
        }
    }

     template<typename T>
    void AVL_Tree<T>::levelOrderHelper(Node_Pointer node) const 
    {
        if (node == nullptr)
        {
            return;
        }
        std::queue<Node_Pointer> queue;
        queue.push(node);
        while (!queue.empty())
        {   

            Node_Pointer tmp = queue.front();
            queue.pop();
            std::cout << tmp->val << " ";
            if (tmp->left != nullptr) 
            {
                queue.push(tmp->left);
            } 
            if (tmp->right != nullptr)
            {
                queue.push(tmp->right);
            }
        }
    }



    template<typename T>
    typename AVL_Tree<T>::reference AVL_Tree<T>::findMinHelper(Node_Pointer node) 
    {
        while (node->left)
            node = node->left;
        return node->val;
    }

    template<typename T>
    typename AVL_Tree<T>::const_reference AVL_Tree<T>::findMin() const 
    {
        if (!root) throw std::runtime_error("Tree is empty");
        Node_Pointer current = root;
        while (current->left)
            current = current->left;
        return current->val;
    }

    template<typename T>
    typename AVL_Tree<T>::const_reference AVL_Tree<T>::findMax() const 
    {
        if (!root) throw std::runtime_error("Tree is empty");
        Node_Pointer current = root;
        while (current->right)
            current = current->right;
        return current->val;
    }

    template<typename T>
    void AVL_Tree<T>::insert(const_reference data)
    {
        root = insertHelper(root, data);
    }

    template<typename T>
    typename AVL_Tree<T>::size_type AVL_Tree<T>::getBalanceFactor(Node_Pointer node) const 
    {
        if (!node) return 0;
        return updateHeight(node->left) - updateHeight(node->right);
    }

    template<typename T>
    typename AVL_Tree<T>::Node_Pointer AVL_Tree<T>::leftRotate(Node_Pointer node) 
    {
        Node_Pointer y = node->right; 
        Node_Pointer T2 = y->left; 

        y->left = node; 
        node->right = T2;

        updateHeight(node);
        updateHeight(y);

        return y; 
    }

    template<typename T>
    typename AVL_Tree<T>::Node_Pointer AVL_Tree<T>::rightRotate(Node_Pointer node) 
    {
        Node_Pointer y = node->left; 
        Node_Pointer T2 = y->right; 

        y->right = node; 
        node->left = T2;

        updateHeight(node);
        updateHeight(y);

        return y; 
    }

    template<typename T>
    typename AVL_Tree<T>::Node_Pointer AVL_Tree<T>::insertHelper(Node_Pointer node , const_reference data)
    {
        if (!node)
            return new Node(data);
        
        if (data < node->val)
            node->left = insertHelper(node->left, data);
        else if (data > node->val)
            node->right = insertHelper(node->right, data);
        else
            return node;

        updateHeight(node);

        int BF = getBalanceFactor(node);

        if (BF > 1 && data < node->left->val)
            return rightRotate(node);

        if (BF < -1 && data > node->right->val)
            return leftRotate(node);

        if (BF > 1 && data > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (BF < -1 && data < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; 
    }

    template<typename T>
    void AVL_Tree<T>::remove(const_reference data)
    {
        root = removeHelper(root, data);
    }

    template<typename T>
    typename AVL_Tree<T>::Node_Pointer AVL_Tree<T>::removeHelper(Node_Pointer node , const_reference data)
    {
        if (!node) return nullptr;

        if (data < node->val)
            node->left = removeHelper(node->left, data);
        else if (data > node->val)
            node->right = removeHelper(node->right, data);
        else 
        {
            if (!node->left || !node->right)
            {
                Node_Pointer temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else
                    *node = *temp;
                delete temp;
            }
            else
            {
                value_type temp = findMinHelper(node->right);
                node->val = temp;
                node->right = removeHelper(node->right, temp);
            }
        }

        if (!node) return node;

        updateHeight(node);

        int BF = getBalanceFactor(node);

        if (BF > 1 && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);

        if (BF > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (BF < -1 && getBalanceFactor(node->right) <= 0)
            return leftRotate(node);

        if (BF < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; 
    }

    template<typename T>
    bool AVL_Tree<T>::contains(const_reference val) const 
    {
        return find(root , val) != false;
    }

    template<typename T>
    int AVL_Tree<T>::getSuccessor(const_reference val) const
    {
        Node_Pointer suc = nullptr;
        
        Node_Pointer temp1 = this->root;
        while (temp1)
        {
            if (temp1->val > val)
            {
                suc = temp1;
                temp1 = temp1->left;
            } else 
            {
                temp1 = temp1->right;
            }
        } 
        if (suc)
        {
            return suc->val;
        } else 
        {
            throw std::runtime_error("Value not found");
        }
    }

    template<typename T>
    int AVL_Tree<T>::getPredecessor(const_reference val) const
    {
        Node_Pointer suc = nullptr;
        
        Node_Pointer temp1 = this->root;
        while (temp1)
        {
            if (temp1->val > val)
            {
                suc = temp1;
                temp1 = temp1->right;
            } else 
            {
                temp1 = temp1->left;
            }
        } 
        if (suc)
        {
            return suc->val;
        } else 
        {
            throw std::runtime_error("Value not found");
        }
    }
} // namespace AVL
