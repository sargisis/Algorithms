
// * @param Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// * @ Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        std::unordered_map<int, int> count; 
        std::unordered_map<int, int> firstInd;
        std::unordered_map<int, int> lastInd; 
        for (size_t i = 0; i < nums.size(); ++i) 
        {
            if (!count.contains(nums[i]))
            {
                firstInd[nums[i]] = i;
            }
            count[nums[i]]++;
            lastInd[nums[i]] = i;
        }    

        int max = 0; 

        for (const auto& pair : count) 
        {
            max = max > pair.second ? max : pair.second; 
        }

        int length = nums.size(); 
        for (const auto& pair : count ) {
            if (pair.second == max) 
            {
                length = length > lastInd[pair.first] - firstInd[pair.first] + 1 ? lastInd[pair.first] - firstInd[pair.first] + 1 : length;
            }
        }
        return length;
    }
};