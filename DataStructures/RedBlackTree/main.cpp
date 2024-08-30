#include "RB.h"

using namespace RB;

int main()
{
    RBTree<int> a(5);
    a.insert(10);
    a.insert(20);
    a.insert(30);
    a.insert(55);
    a.insert(65);
    a.levelOrder();
    std::cout << "--------------" << std::endl;
    a.levelOrder();

  
   

    


    
    
}