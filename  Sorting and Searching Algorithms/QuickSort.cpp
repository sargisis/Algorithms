#include <iostream>
#include <chrono>
#include <vector>
#include <utility>

using std::vector;

int partition(vector<int>& arr, int low, int high);

void quick_sort_algorithm(vector<int>& arr, int low , int high) 
{
    if (low < high)
    {
        int mid = partition(arr , low , high);
        quick_sort_algorithm(arr, low , mid - 1);
        quick_sort_algorithm(arr, mid + 1 , high);
    }
}

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

void print(vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
}

int main() 
{
    vector<int> arr = {2,8,7,1,3,5,6,4};

    
    auto start = std::chrono::high_resolution_clock::now();
    quick_sort_algorithm(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr);
    std::cout << "Quick sort taken " << elapsed.count() << "miliseconds" << std::endl; 
    
    return 0;
}


