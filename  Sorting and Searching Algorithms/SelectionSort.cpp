#include <iostream>


int selection_sort_algorithm(int* arr, int size) {
    for (size_t i = 0; i < size - 1; ++i) {
        int ind = i; 
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[j] < arr[ind]) {
                ind = j; 
            }
        }
        std::swap(arr[i] , arr[ind]);
    }
    return -1; 
}

int main() {
    int arr[] = {99 , 3, 2 ,1 , 7 , 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Before sorting " << std::endl; 
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
    int result = selection_sort_algorithm(arr,size);
    
    std::cout << "Sorting with help selection sort " << std::endl; 
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 

    return 0;
}