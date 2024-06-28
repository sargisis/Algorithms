// * @param 1636. Sort Array by Increasing Frequency // 

// * @param Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

// * @param Return the sorted array.

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int , int> map; 
        for (size_t i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
        }
 
        std::sort(nums.begin() , nums.end(), [&](int a , int b){
            return map[a] != map[b] ? map[a] < map[b] : a > b;
        });
        return nums; 
    }
};