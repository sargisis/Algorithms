#include <iostream>
#include <chrono>

// * @param Buble sort Algorithm //  

void buble_sort_argorithm(int* arr, int size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]){
                 std::swap(arr[j] , arr[j + 1]);
            }
        }
    }
  
}

void print(int* arr , int size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main () {
    int arr[] = {99,33,11,22,33};
    int size = sizeof(arr) / sizeof(arr[0]);
   
    auto start = std::chrono::high_resolution_clock::now(); 
    buble_sort_argorithm(arr,size);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr,size);
    std::cout << "Buble sort taken" << elapsed.count() << "miliseconds" << std::endl;  
    

}