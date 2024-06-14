#include "../DataStructures/forward_list.h"


int main() {
    g3::forward_list<int> s {1,2,3,4,6,7,8,9};
    s.insert_after(s.cbegin() , 55);
    for (auto it : s) {
        std::cout << it << " " << std::endl; 
    }
}