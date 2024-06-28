#include <iostream>
#include <chrono>
#include <vector>
#include <utility>
#include <time.h>
#include <cstdlib>

using std::vector;

int partition(vector<int>& arr, int low, int high);
int partition_r(vector<int>& arr, int low, int high);
void sortFirstMiddleLast(vector<int>& arr, int first , int mid , int last);

void quick_sort_algorithm(vector<int>& arr, int low , int high) 
{
    if (low < high)
    {
        int mid = partition_r(arr , low , high);
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


int partition_r(vector<int>& arr, int low , int high)
{
    srand(0);
    int random = low + rand() % (high - low);

    sortFirstMiddleLast(arr, random ,low , high);
    std::swap(arr[random] , arr[high]);

    return partition(arr, low , high);
}

void sortFirstMiddleLast(vector<int>& arr, int first , int mid , int last)
{
    if (arr[first] > arr[mid])
    {
        std::swap(arr[first] , arr[mid]);
    }
    if (arr[mid] > arr[last])
    {
        std::swap(arr[mid] , arr[last]);
    }
    if (arr[first] > arr[mid])
    {
        std::swap(arr[first] , arr[mid]);
    }
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
    vector<int> arr = {2,8,7,13333333,5,6,4, 0, 1, 5, 1};

    
    auto start = std::chrono::high_resolution_clock::now();
    quick_sort_algorithm(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr);
    std::cout << "Quick sort taken " << elapsed.count() << "miliseconds" << std::endl; 
    
    return 0;
}


