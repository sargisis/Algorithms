// * @param Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

class Solution {
public:
    int partition(vector<int>& arr, int low , int high)
    {
        int pivot = arr[high];
        int i = low - 1; 
        for (int j = low; j <= high - 1; ++j)
        {
            if (arr[j] < pivot)
            {
                ++i;
                std::swap(arr[i] , arr[j]);
            }
        }
        
        std::swap(arr[i + 1] , arr[high]);
        
        return i + 1; 
    }

    void quick_sort(vector<int>& arr, int left , int right)
    {
        if (left < right)
        {
            int mid = partition(arr, left , right);
            quick_sort(arr, left , mid - 1);
            quick_sort(arr, mid + 1, right);
        }
    }

    void power_arrays(vector<int>& arr, int power)
    {
        for (size_t i = 0; i < arr.size(); ++i)
        {
            arr[i] = std::pow(arr[i], power);
        }
        quick_sort(arr, 0 , arr.size() - 1);
    } 

    vector<int> sortedSquares(vector<int>& nums) 
    {
        int power = 2;
        power_arrays(nums, power);
        return nums;
    }
};