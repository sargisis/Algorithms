// * @param 169. Majority Element // 

// * @param Given an array nums of size n, return the majority element.

// * @param The majority element is the element that appears more than ⌊n / 2⌋ times. 

// * @param You may assume that the majority element always exists in the array.

#include <vector>
#include <algorithm>



class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin() , nums.end());
        int count = 0, majory_element = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) majory_element = nums[i];
            if (majory_element == nums[i]) ++count; 
            else --count;
        }
        return majory_element;
    }
};