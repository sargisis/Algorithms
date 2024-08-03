#include "BST.h"

using namespace BST;

int main()
{
    Binary_Search_Tree<int> tree;
    tree.insert(44);
    tree.insert(4);
    tree.insert(2);
    tree.insert(422);
   
    // int result = tree.getPredecessor(422);
    // if (result)
    // {
    //     std::cout << "This value has predsuccsessor " << result << std::endl; 
    // } else 
    // {
    //     std::cout << "This value doesn't have predsuccessor" << std::endl; 
    // }

    // int result1 = tree.getSuccessor(44);
    // if (result1)
    // {
    //     std::cout << "This value has successor " << result1 << std::endl;
    // }
    // else 
    // {
    //     std::cout << "This value doesn't have successor " << std::endl; 
    // }


    std::cout << tree.find(33);
    tree.inOrderTraversal();

    return 0;
}