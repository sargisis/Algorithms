#include <iostream>
#include <chrono>
#include <vector>

using std::vector;


// * @param Selection sort algorithm // 

void selection_sort_algorithm(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        int ind = i; 
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[ind]) {
                ind = j; 
            }
        }
        std::swap(arr[i] , arr[ind]);
    }  
}

void print(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}


int main() {
    vector<int> arr = {99 , 3, 2 ,1 , 7 , 5, 3};
    
    auto start = std::chrono::high_resolution_clock::now();
    selection_sort_algorithm(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr);
    std::cout << "Selection sort taken" << elapsed.count() << "miliseconds" << std::endl; 

    return 0;
}