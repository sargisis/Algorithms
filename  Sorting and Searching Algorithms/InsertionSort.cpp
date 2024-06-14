#include <iostream>
#include <chrono>


// * @param Insertion sort algorithm //

void insertion_sort_algorithm(int* arr, int size) {
    for (size_t i = 1; i < size; ++i) {
        int result = arr[i];
        int j = i - 1; 
        while (j >= 0 && arr[j] > result) {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = result; 
    }
}

void print(int* arr , int size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {99,33,1,5,99,33,44}; 
    int size = sizeof(arr) / sizeof(arr[0]);
   
    auto start = std::chrono::high_resolution_clock::now(); 
    insertion_sort_algorithm(arr,size);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> elapsed = end - start;
    print(arr, size);

    std::cout << "Insertion sort taken " << elapsed.count() << "miliseconds" << std::endl; 
}

