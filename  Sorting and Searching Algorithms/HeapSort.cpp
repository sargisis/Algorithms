#include <iostream>
#include <vector>
#include <chrono>

using std::vector;

void maxHeapify(vector<int>& arr, int size ,  int i)
{
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < size && arr[left] > arr[largest])
    {
        largest = left; 
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right; 
    }

    if (largest != i)
    {
        std::swap(arr[i] , arr[largest]);

        maxHeapify(arr , size , i);
    }
}

void buildMaxHeap(vector<int>& arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; --i)
    {
        maxHeapify(arr,arr.size(), i);
    }
}

void heap_sort(vector<int>& arr)
{
    buildMaxHeap(arr);
    for (int i = arr.size() / 2 - 1; i >= 0; --i)
    {
        std::swap(arr[i] , arr[0]);
        maxHeapify(arr, i, 0);
    }
}


void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Create a vector representing a binary tree (array form)
    std::vector<int> arr = {3, 9, 2, 1, 4, 5};



    auto start = std::chrono::high_resolution_clock::now();
    heap_sort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    printArray(arr);

    std::cout << "Heapify taken " << elapsed.count() << std::endl; 
   

    return 0;
}

