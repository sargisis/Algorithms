#include <iostream>

int insertion_sort_algorithm(int* arr, int size) {
    for (size_t i = 1; i < size; ++i) {
        int result = arr[i];
        int j = i - 1; 
        while (j >= 0 && arr[j] > result) {
            arr[j + 1] = arr[j];
            --j;
        }
        
        arr[j + 1] = result; 
    }
    return -1;
}

int main() {
    int arr[] = {99,33,1,5,99,33,44}; 
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Before sorting " << std::endl; 
    for (size_t i = 0; i < size; ++i ) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
    int result = insertion_sort_algorithm(arr,size);
    std::cout << "Sorting with help insertion sort " << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

