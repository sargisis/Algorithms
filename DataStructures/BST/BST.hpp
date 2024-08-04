#pragma once

#include "BST.h"

namespace BST
{
    template <typename T>
    Binary_Search_Tree<T>::Binary_Search_Tree()
        : root{nullptr}
    {
    }

    template <typename T>
    Binary_Search_Tree<T>::Binary_Search_Tree(const_reference data)
        : root{new Node(data)}
    {
    }

    template<typename T>
    Binary_Search_Tree<T>::~Binary_Search_Tree() noexcept
    {
        clear_recursive(this->root);
    }

    template <typename T>
    Binary_Search_Tree<T>::const_reference Binary_Search_Tree<T>::findMin() const
    {
        const_Node_pointer node = this->root;
        if (node == nullptr)
        {
            throw std::runtime_error("Left tree is empty");
        }

        while (node->m_left != nullptr)
        {
            node = node->m_left;
        }
        return node->m_data;
    }

    template <typename T>
    Binary_Search_Tree<T>::reference Binary_Search_Tree<T>::findMin()
    {
        Node_Pointer node = this->root;
        if (node == nullptr)
        {
            throw std::runtime_error("Left tree is empty");
        }

        while (node->m_left != nullptr)
        {
            node = node->m_left;
        }
        return node->m_data;
    }

    template <typename T>
    Binary_Search_Tree<T>::const_reference Binary_Search_Tree<T>::findMax() const
    {
        const_Node_pointer node = this->root;
        if (node == nullptr)
        {
            throw std::runtime_error("Right tree is empty");
        }

        while (node->m_right != nullptr)
        {
            node = node->m_right;
        }
        return node->m_data;
    }

    template<typename T>
    bool Binary_Search_Tree<T>::is_empty() const 
    {
        return this->root == 0;
    }

    template <typename T>
    Binary_Search_Tree<T>::reference Binary_Search_Tree<T>::findMax()
    {
        Node_Pointer node = this->root;
        if (node == nullptr)
        {
            throw std::runtime_error("Right tree is empty");
        }

        while (node->m_right != nullptr)
        {
            node = node->m_right;
        }
        return node->m_data;
    }

    template <typename T>
    Binary_Search_Tree<T>::size_type Binary_Search_Tree<T>::find(const_reference data) const
    {
        return findHelper(this->root, data);
    }

    template <typename T>
    Binary_Search_Tree<T>::size_type Binary_Search_Tree<T>::find(reference data)
    {
        return findHelper(this->root, data);
    }

    template <typename T>
    Binary_Search_Tree<T>::const_reference Binary_Search_Tree<T>::findHelper(Node_Pointer node, const_reference data) const
    {   
        if (!node)
        {
            throw std::runtime_error("Error:");
        }
        if (node->m_data == data)
        {
            return node->m_data;
        }

        if (node->m_data > data)
        {
            return findHelper(node->m_left, data);
        }
        else 
        {
            return findHelper(node->m_right, data);
        }        
    }

    template <typename T>
    void Binary_Search_Tree<T>::insert(const_reference data)
    {
        if (!root)
        {
            root = new Node(data);
        }
        else
        {
            insertHelper(this->root, data);
        }
    }

    template<typename T>
    Binary_Search_Tree<T>::Node_Pointer Binary_Search_Tree<T>::clear_recursive(Node_Pointer node) 
    {
        if (node != nullptr)
        {
            clear_recursive(node->m_left);
            clear_recursive(node->m_right);
            delete node; 
        }
        return nullptr;
    }

    template<typename T>
    Binary_Search_Tree<T>::Node_Pointer Binary_Search_Tree<T>::clear_iterative(Node_Pointer node)
    {
        if (node != nullptr)
        {
            return node; 
        }
        std::stack<Node_Pointer> st;
        while (!st.empty())
        {
            Node_Pointer tmp = st.top();
            st.pop();
            if (tmp->m_left != nullptr)
            {
                st.push(tmp->m_left);
            }
            if (tmp->m_right != nullptr)
            {
                st.push(tmp->m_right);
            }
            delete node;
        }
        node = nullptr;
    }

    template <typename T>
    Binary_Search_Tree<T>::Node_Pointer Binary_Search_Tree<T>::insertHelper(Node_Pointer node, const_reference data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }

        if (data < node->m_data)
        {
            node->m_left = insertHelper(node->m_left, data);
        }
        else if (data > node->m_data)
        {
            node->m_right = insertHelper(node->m_right, data);
        }

        return node;
    }

    template <typename T>
    void Binary_Search_Tree<T>::remove(const_reference data)
    {
        if (!root)
        {
            delete root;
        }
        else
        {
            removeHelper(this->root, data);
        }
    }

    template <typename T>
    Binary_Search_Tree<T>::Node_Pointer Binary_Search_Tree<T>::removeHelper(Node_Pointer node, const_reference data)
    {

        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->m_data > data)
        {
            node->m_left = removeHelper(node->m_left, data);
        }
        else if (node->m_data < data)
        {
            node->m_right = removeHelper(node->m_right, data);
        }
        else
        {
            if (node->m_left == nullptr)
            {
                return node->m_right;
            }
            else if (node->m_right == nullptr)
            {
                return node->m_left;
            }
            else
            {
                value_type min_value = findMinHelper(node->m_right);
                node->m_data = min_value;
                node->m_right = removeHelper(node->m_right, data);
            }
        }
        return node;
    }

    template <typename T>
    void Binary_Search_Tree<T>::preOrderHelper(Node_Pointer node) const
    {
        if (node != nullptr)
        {
            std::cout << node->m_data << " ";
            preOrderHelper(node->m_left);
            preOrderHelper(node->m_right);
        }
    }

    template <typename T>
    void Binary_Search_Tree<T>::inOrderHelper(Node_Pointer node) const
    {
        if (node != nullptr)
        {
            inOrderHelper(node->m_left);
            std::cout << node->m_data << " ";
            inOrderHelper(node->m_right);
        }
    }

    template <typename T>
    void Binary_Search_Tree<T>::postOrderHelper(Node_Pointer node) const
    {
        if (node != nullptr)
        {
            postOrderHelper(node->m_left);
            postOrderHelper(node->m_right);
            std::cout << node->m_data << " ";
        }
    }

    template<typename T>
    void Binary_Search_Tree<T>::levelOrderHelper(Node_Pointer node) const 
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
            std::cout << tmp->m_data << " ";
            if (tmp->m_left != nullptr) 
            {
                queue.push(tmp->m_left);
            } 
            if (tmp->m_right != nullptr)
            {
                queue.push(tmp->m_right);
            }
        }
    }



    template <typename T>
    void Binary_Search_Tree<T>::preOrderTraversal() const
    {
        preOrderHelper(this->root);
    }

    template <typename T>
    void Binary_Search_Tree<T>::inOrderTraversal() const
    {
        inOrderHelper(this->root);
    }

    template <typename T>
    void Binary_Search_Tree<T>::postOrderTraversal() const
    {
        postOrderHelper(this->root);
    }

    template<typename T>
    void Binary_Search_Tree<T>::levelOrderTraversal() const 
    {
        levelOrderHelper(this->root);
    }

    template <typename T>
    Binary_Search_Tree<T>::reference Binary_Search_Tree<T>::findMinHelper(Node_Pointer node)
    {
        if (node->m_left)
        {
            return findMinHelper(node->m_left);
        }
        return node->m_data;
    }

    template <typename T>
    Binary_Search_Tree<T>::const_reference Binary_Search_Tree<T>::findMinHelper(const_Node_pointer node) const
    {
        if (node->m_left)
        {
            return findMinHelper(node->m_left);
        }
        return node->m_data;
    }

    template<typename T>
    Binary_Search_Tree<T>::const_reference Binary_Search_Tree<T>::findMaxHelper(const_Node_pointer node) const 
    {
        if (node->m_right)
        {
            return findMaxHelper(node->m_right);
        }
        return node->m_data; 
    }

    template<typename T>
    Binary_Search_Tree<T>::reference Binary_Search_Tree<T>::findMaxHelper(Node_Pointer node) 
    {
        if (node->m_right)
        {
            return findMaxHelper(node->m_right);
        }
        return node->m_data; 
    }   

    template<typename T>
    int Binary_Search_Tree<T>::getSuccessor(const_reference val) const
    {
        Node_Pointer suc = nullptr;

        Node_Pointer temp1 = this->root;
        while (temp1)
        {
            if (temp1->m_data > val)
            {
                suc = temp1;
                temp1 = temp1->m_left;
            } else 
            {
                temp1 = temp1->m_right;
            }
        } 
        if (suc)
        {
            return suc->m_data;
        } else 
        {
            throw std::runtime_error("Value not found");
        }
    } 
    
    template<typename T>
    int Binary_Search_Tree<T>::getPredecessor(const_reference val) const 
    {
      
        Node_Pointer pre = nullptr;

        Node_Pointer temp1 = this->root;
        while (temp1)
        {
            if (temp1->m_data < val)
            {
                pre = temp1;
                temp1 = temp1->m_right;   
            } else
            {
                temp1 = temp1->m_left;
            } 
        }
        if (pre)
        {
            return pre->m_data;
        } else 
        {
            throw std::runtime_error("Value not found");
        }
        
    }

    template<typename T>
    void Binary_Search_Tree<T>::inOrderIterative(Node_Pointer node) const 
    {
        if (node == nullptr)
        {
            return;
        }
        std::stack<Node_Pointer> st;
        while (!st.empty())
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->m_left;
            }
            else 
            {
                node = st.top();
                st.pop();
                std::cout << node->m_data << " ";
                node = node->m_right;
            }
        }
    }

    template<typename T>
    void Binary_Search_Tree<T>::preOrderIterative(Node_Pointer node) const 
    {
        if (node == nullptr)
        {
            return;
        }
        std::stack<Node_Pointer> st;
        while (!st.empty())
        {
            if (node != nullptr)
            {
                st.push(node);
                std::cout << node->m_data << " ";
                node = node->m_left;
            }
            else 
            {
                node = st.top();
                st.pop();
                node = node->m_right;
            }
        }
    }

    template<typename T>
    void Binary_Search_Tree<T>::postOrderIterative(Node_Pointer node) const
    {
        if (node == nullptr)
        {
            return;
        }
        
        std::stack<Node_Pointer> st,st1;
        st.push(node);
        while (!st.empty())
        {
            Node_Pointer tmp = st.top();
            st.pop();
            st1.push(node);

            if (tmp->m_left != nullptr)
            {
                st.push(tmp->m_left);
            }
            
            if (tmp->m_right != nullptr)
            {
                st.push(tmp->m_right);
            }
        }
        while (!st1.empty())
        {
            std::cout << st1.top() << " ";
            st1.pop();
        }
    }

    template<typename T>
    void Binary_Search_Tree<T>::levelOrderIterative(Node_Pointer node) const 
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
            std::cout << tmp->m_data << " ";
            if (tmp->m_left != nullptr) 
            {
                queue.push(tmp->m_left);
            } 
            if (tmp->m_right != nullptr)
            {
                queue.push(tmp->m_right);
            }
        }
    }

    template<typename T>
    bool Binary_Search_Tree<T>::contains(const_reference val) const 
    {
        if (find(val))
        {
            return true;
        }
        return false; 
    }

    template<typename T>
    Binary_Search_Tree<T>::size_type Binary_Search_Tree<T>::getHeight() const 
    {
        return getHeightHelper(this->root);
    }   

    template<typename T>
    Binary_Search_Tree<T>::size_type Binary_Search_Tree<T>::getHeightHelper(Node_Pointer node) const 
    {
        if (node == nullptr)
        {
            return 0; 
        }

        auto leftHeight = getHeightHelper(node->m_left);
        auto rightHeight = getHeightHelper(node->m_right);

        return 1 + std::max(leftHeight , rightHeight);
    }
}
