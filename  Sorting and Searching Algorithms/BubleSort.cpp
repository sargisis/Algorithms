#include <iostream>
#include <chrono>
#include <vector>

using std::vector;
// * @param Buble sort Algorithm //  

void buble_sort_argorithm(vector<int>& arr) {
    bool flag = true;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        flag = true; 
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]){
                 std::swap(arr[j] , arr[j + 1]);
                flag = false; 
            }
        }
        if (flag)
        {
            break;
        }
    }
  
}

void print(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}

int main () {
    vector<int> arr = {1,2,3,4,5};
   
    auto start = std::chrono::high_resolution_clock::now(); 
    buble_sort_argorithm(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr);
    std::cout << "Buble sort taken" << elapsed.count() << "miliseconds" << std::endl;  
    
}