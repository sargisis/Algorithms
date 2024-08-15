#include <iostream>
#include "AVL.h"

using namespace AVL;

int main() {
    // Create an AVL Tree and insert elements
    AVL_Tree<int> tree;
    
    std::cout << "Inserting elements..." << std::endl;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    // Test in-order traversal (should print in sorted order)
    std::cout << "In-order traversal: ";
    tree.inOrderTraversal();
    std::cout << std::endl;

    // Test pre-order traversal
    std::cout << "Pre-order traversal: ";
    tree.preOrderTraversal();
    std::cout << std::endl;

    // Test post-order traversal
    std::cout << "Post-order traversal: ";
    tree.postOrderTraversal();
    std::cout << std::endl;

    // Test level-order traversal
    std::cout << "Level-order traversal: ";
    tree.levelOrderTraversal();
    std::cout << std::endl;

    // Test finding minimum and maximum values
    std::cout << "Minimum value in the tree: " << tree.findMin() << std::endl;
    std::cout << "Maximum value in the tree: " << tree.findMax() << std::endl;

    // Test height of the tree
    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;

    // Test contains function
    int value = 15;
    if (tree.contains(value)) {
        std::cout << "Tree contains " << value << std::endl;
    } else {
        std::cout << "Tree does not contain " << value << std::endl;
    }

    // Test finding successor and predecessor
    int target = 15;
    try {
        int successor = tree.getSuccessor(target);
        std::cout << "Successor of " << target << " is " << successor << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        int predecessor = tree.getPredecessor(target);
        std::cout << "Predecessor of " << target << " is " << predecessor << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test removal of elements
    std::cout << "Removing element 20..." << std::endl;
    tree.remove(20);
    std::cout << "In-order traversal after removal: ";
    tree.inOrderTraversal();
    std::cout << std::endl;

    tree.rightRotate();
    tree.inOrderTraversal();

    return 0;
}
