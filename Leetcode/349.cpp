// * @param 349. Intersection of Two Arrays // 

// * @param Given two integer arrays nums1 and nums2, return an array of their intersection.
// * @param Each element in the result must be unique and you may return the result in any order.

#include <vector>
#include <set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
       std::set<int> set1; 
       std::set<int> set2; 
       std::vector<int> result; 
       for (auto it : nums1) {
          set1.insert(it); 
       }
       for (auto it1 : nums2) {
          set2.insert(it1); 
       }
       auto it1 = set1.begin();
       auto it2 = set2.begin(); 
       while (it1 != set1.end() && it2 != set2.end()) {
            if (*it1 == *it2) {
                result.push_back(*it1);
                ++it1;
                ++it2;
            }
            if (*it1 < *it2) {
                *it1++; 
            }
            else if (*it1 > *it2) {
                *it2++; 
            }
      }
        return result; 
    }
};