#include <iostream>

int buble_sort_argorithm(int* arr, int size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]){
                 std::swap(arr[j] , arr[j + 1]);
            }
        }
    }
    
    return -1; 
}

int main () {
    int arr[] = {99,33,11,22,33};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Before Sort " << std::endl; 
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
    size_t result = buble_sort_argorithm(arr,size);
    std::cout << "Sorting with help BubleSort " << std::endl; 
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

}