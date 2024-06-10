// * @param 217. Contains Duplicate // 

// * @param Given an integer array nums, return true if any value appears at least twice in the array, 
// * @param and return false if every element is distinct.

#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& arr) {
        std::sort(arr.begin() , arr.end());
        int N = arr.size();
        for (int i = 1; i < N; ++i) {
            if (arr[i] == arr[i - 1]) {
                return true;
            }
        }
        return false; 
    }
};