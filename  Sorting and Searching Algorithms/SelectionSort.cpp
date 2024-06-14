#include <iostream>
#include <chrono>

// * @param Selection sort algorithm // 

void selection_sort_algorithm(int* arr, int size) {
    for (size_t i = 0; i < size - 1; ++i) {
        int ind = i; 
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[j] < arr[ind]) {
                ind = j; 
            }
        }
        std::swap(arr[i] , arr[ind]);
    }  
}

void print(int* arr , int size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}


int main() {
    int arr[] = {99 , 3, 2 ,1 , 7 , 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    auto start = std::chrono::high_resolution_clock::now();
    selection_sort_algorithm(arr,size);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr,size);
    std::cout << "Selection sort taken" << elapsed.count() << "miliseconds" << std::endl; 
    

    return 0;
}