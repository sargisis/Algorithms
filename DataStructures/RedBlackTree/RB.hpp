#pragma once 

#include <iostream>

#include "RB.h"


namespace RB {
    template <typename T>
    RBTree<T>::RBTree()
    {
        NIL = new Node();  
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL;
        root = NIL;
    }

    template <typename T>
    RBTree<T>::RBTree(const_reference val)
    {
        NIL = new Node(); 
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = NIL;

        root = new Node(val);  
        root->color = BLACK;   
        root->left = root->right = root->parent = NIL;
    }

    template <typename T>
    RBTree<T>::~RBTree() 
    {
        clear(root);
        delete NIL;
    }


   template <typename T>
   void RBTree<T>::inOrderTraversal()
   {
        inOrderHelper(root);
   }


   template <typename T>
   void RBTree<T>::inOrderHelper(Node_Pointer node) 
   {
        if (node != NIL)
        {
            inOrderHelper(node->left);
            std::cout << node->val << " ";
            inOrderHelper(node->right);
        }
   }

   template <typename T>
   RBTree<T>::Node_Pointer RBTree<T>::search(size_type val)
   {
        return searchTreeHelper(root, val);
   }

   template <typename T>
   RBTree<T>::Node_Pointer RBTree<T>::searchTreeHelper(Node_Pointer node , size_type val)
   {
        if (!node)
        {
            return NIL;
        }
        if (node->val > val)
        {
            return searchTreeHelper(node->left , val);
        } 
        else if (node->val < val)
        {
            return searchTreeHelper(node->right , val);
        }
        else 
        {
            return node; 
        }
   }

   template <typename T>
   RBTree<T>::Node_Pointer RBTree<T>::findMin(Node_Pointer node)
   {
        Node_Pointer suc = nullptr;
        
        Node_Pointer temp1 = this->root;
        while (temp1)
        {
            if (temp1->val > node->val)
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
            return suc;
        } else 
        {
            throw std::runtime_error("Value not found");
        }
      
   }

   template <typename T>
   RBTree<T>::Node_Pointer RBTree<T>::findMax(Node_Pointer node)
   {
        if (node == NIL)
        {
            return NIL;
        }
        while (node && node->right != NIL)
        {
            node = node->right;
        }
        return node;
   }

   template <typename T>
   void RBTree<T>::clear(Node_Pointer node) noexcept 
   {
        if (node != NIL)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
   }

   template <typename T>
   void RBTree<T>::leftRotate(Node_Pointer node)
   {
       
    Node_Pointer y = node->right;
    node->right = y->left;
    if (y->left != NIL)
    {
        y->left->parent = node;
    }
    y->parent = node->parent;
    if (node->parent == NIL)
    {
        root = y;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = y;
    }
    else
    {
        node->parent->right = y;
    }
    y->left = node;
    node->parent = y;
 
   }

   template <typename T>
   void RBTree<T>::rightRotate(Node_Pointer node)
   {

    Node_Pointer x = node->left;
    node->left = x->right;
    if (x->right != NIL)
    {
        x->right->parent = node;
    }
    x->parent = node->parent;
    if (node->parent == NIL)
    {
        root = x;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = x;
    }
    else
    {
        node->parent->left = x;
    }
    x->right = node;
    node->parent = x;
   }

    template <typename T>
    RBTree<T>::Node_Pointer RBTree<T>::insert(size_type val)
    {
        if (root == NIL)
        {
            root = new Node(val);        
            root->left = root->right = NIL; 
            root->parent = NIL;             
            root->color = BLACK;            
            return root;
        }

       
        Node_Pointer newNode = insertNodeHelper(root, val);
        
       
        insertFixUP(newNode);

        return newNode;
    }
    template <typename T>
    RBTree<T>::Node_Pointer RBTree<T>::insertNodeHelper(Node_Pointer node, size_type val){
        Node_Pointer newNode = new Node(val);
        newNode->left = newNode->right = NIL;

        Node_Pointer y = NIL;
        Node_Pointer x = root;

        while (x != NIL)
        {
            y = x;
            if (newNode->val < x->val)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        newNode->parent = y;
        if (y == NIL)
        {
            root = newNode;
        }
        else if (newNode->val < y->val)
        {
            y->left = newNode;
        }
        else
        {
            y->right = newNode;
        }   
        newNode->color = RED;

        insertFixUP(newNode);

        return newNode;
    }

    template <typename T>
    RBTree<T>::Node_Pointer RBTree<T>::insertFixUP(Node_Pointer node)  
    {   
    Node_Pointer uncle = NIL;
    while (node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->left)
        {
            uncle = node->parent->parent->right;
            
            if (uncle->color == RED) // Case 1: Uncle is red
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else // Case 2 & 3: Uncle is black
            {
                if (node == node->parent->right) // Case 2: Node is right child
                {
                    node = node->parent;
                    leftRotate(node);
                }

                // Case 3: Node is left child
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(node->parent->parent);
            }
        } 
        else // Symmetric case for when parent is a right child
        {
            uncle = node->parent->parent->left;
            
            if (uncle->color == RED) // Case 1: Uncle is red
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } 
            else // Case 2 & 3: Uncle is black
            {
                if (node == node->parent->left) // Case 2: Node is left child
                {
                    node = node->parent;
                    rightRotate(node);
                }
                // Case 3: Node is right child
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->color = BLACK; // Ensure the root is always black
    return node; 
}



    template <typename T>
    void RBTree<T>::Transplant(Node_Pointer u , Node_Pointer v)
    {
        if (u->parent == NIL)
        {
             root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else 
        {
           u->parent->right = v;
        }
        if (v != NIL)
        {
            v->parent = u->parent;
        }
    }

    template <typename T>
    void RBTree<T>::remove(size_type val)
    {   
      
        Node_Pointer node = root;
        while (node != NIL && node->val != val)
        {
        
            if (val < node->val)
            {
                node = node->left;
            }
            else 
            {
                node = node->right; 
            }
        }
        if (node != NIL){
             deleteNodeHelper(node , val);
        }    
    }

    template <typename T>
    void RBTree<T>::deleteNodeHelper(Node_Pointer node, size_type val) {
    Node_Pointer y = node;
    Node_Pointer x = NIL;
    Color yOriginalColor = y->color;

    if (node->left == NIL) 
    {
        x = node->right;
        Transplant(node, node->right);
    } 
    else if (node->right == NIL) 
    {
        x = node->left;
        Transplant(node, node->left);
    } 
    else 
    {
        y = findMin(node->right);
        yOriginalColor = y->color;
        x = y->right;
        
        if (y->parent != node) 
        {
            Transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        Transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    
    if (yOriginalColor == BLACK) 
    {
        removeFixUP(x);
    }
}


   template <typename T>
   void RBTree<T>::removeFixUP(Node_Pointer x) {
    while (x != root && x->color == BLACK) 
    {
        if (x == x->parent->left)
         {
            Node_Pointer w = x->parent->right; // w is x's sibling
            
            if (w->color == RED) 
            { // Case 1: x's sibling w is red
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK) 
            { // Case 2: w's children are black
                w->color = RED;
                x = x->parent;
            } else 
            {
                if (w->right->color == BLACK) 
                { // Case 3: w's right child is black
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                
                // Case 4: w's right child is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else 
        { // Same as above, but with left and right swapped
            Node_Pointer w = x->parent->left; // w is x's sibling
            
            if (w->color == RED) 
            { // Case 1: x's sibling w is red
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            
            if (w->left->color == BLACK && w->right->color == BLACK) 
            { // Case 2: w's children are black
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) 
                { // Case 3: w's left child is black
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                
                // Case 4: w's left child is red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    
   x->color = BLACK;

}

 template <typename T>
 void RBTree<T>::levelOrder()
 {
    levelOrderHelper(root);
 }

 template <typename T>
 void RBTree<T>::levelOrderHelper(Node_Pointer node)
 {
      if (root == NIL)
    {
        return;
    }

    std::queue<Node_Pointer> q;
    q.push(root);

    while (!q.empty())
    {
        Node_Pointer current = q.front();
        q.pop();

         std::cout << current->val << " (" << (current->color == RED ? "Red" : "Black") << ") ";

        if (current->left != NIL)
        {
            q.push(current->left);
        }
        if (current->right != NIL)
        {
            q.push(current->right);
        }
    }

    std::cout << std::endl;
 }
}
