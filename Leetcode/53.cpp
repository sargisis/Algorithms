#include <iostream>

using namespace std; 

// * @param 53 Max SubArray 

// * @param Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Solving N1 
// time complexity O(n)
// space complexity O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int SumMax = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) 
        {
            sum = std::max(nums[i] , nums[i] + sum);
            SumMax = std::max(SumMax ,sum);
        }
        return SumMax; 
    }
};

// Solving N2 
// time complexity O(n * log n)
// space complexity O(1)

class Solution {
public:
    long long findCrossNumber(std::vector<int>& nums, int start, int mid, int end) {
        long long leftSum = LLONG_MIN; 
        long long rightSum = LLONG_MIN; 
        long long sum = 0; 

        for (int i = mid; i >= start; --i) {
            sum += nums[i];
            if (leftSum < sum) {
                leftSum = sum; 
            }
        }

        sum = 0; 
        for (int i = mid + 1; i <= end; ++i) {
            sum += nums[i];
            if (rightSum < sum) {
                rightSum = sum; 
            }
        }

        return leftSum + rightSum;
    }

    int MaxNumArray(std::vector<int>& arr, int left, int right) {
        if (left == right) {
            return arr[left];
        } else {
            int mid = left + (right - left) / 2; 
            int leftCross = MaxNumArray(arr, left, mid);
            int rightCross = MaxNumArray(arr, mid + 1, right); 
            long long cross = findCrossNumber(arr, left, mid, right);

            return std::max({leftCross, rightCross, (int)cross});
        }
    }

    int maxSubArray(std::vector<int>& nums) {
        return MaxNumArray(nums, 0, nums.size() - 1);
    }   
};

