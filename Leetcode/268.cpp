// * @param 268. Missing Number // 

// * @param Given an array nums containing n distinct numbers in the range [0, n], 
// * @param return the only number in the range that is missing from the array.

#include <vector>
#include <algorithm>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        std::sort(nums.begin() , nums.end());
        int totalsize = nums.size() * (nums.size() + 1 ) / 2;
        int sum{};
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        return totalsize - sum; 
    }
};