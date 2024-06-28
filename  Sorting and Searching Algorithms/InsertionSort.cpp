#include <iostream>
#include <chrono>
#include <vector>

using std::vector; 

// * @param Insertion sort algorithm //

void insertion_sort_algorithm(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int result = arr[i];
        int j = i - 1; 
        while (j >= 0 && arr[j] > result) {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = result; 
    }
}

void print(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
   
    vector<int> arr = {99,33,1,5,99,33,44}; 
    
    auto start = std::chrono::high_resolution_clock::now(); 
    insertion_sort_algorithm(arr);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> elapsed = end - start;
    print(arr);

    std::cout << "Insertion sort taken " << elapsed.count() << "miliseconds" << std::endl; 
}

