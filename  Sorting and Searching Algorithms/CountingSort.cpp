#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> counting_sort_algorithm(std::vector<int>& arr) {
    int N = arr.size(); 


    int MaxNumber = 0; 
    
    for (size_t i = 0; i < N; ++i) {
        MaxNumber = std::max(MaxNumber, arr[i]);
    }

   std::vector<int> count_array(MaxNumber + 1 , 0);
   
   for (int i = 0; i < N; ++i) {
        count_array[arr[i]]++;
   }

    for (int i = 1; i <= MaxNumber; ++i) {
        count_array[i] += count_array[i - 1];
    }

    std::vector<int> output_array(N);

    for (int i = N - 1; i >= 0; --i) {
      output_array[count_array[arr[i]] - 1] = arr[i];
       count_array[arr[i]]--;
    }

    return output_array;
}

int main() {
   
   std::vector<int> input_array = {2,5,3,0,2,3,0,3};

   std::vector<int> output_array = counting_sort_algorithm(input_array);
   for (size_t i = 0; i < input_array.size(); ++i) {
        std::cout << output_array[i] << " ";
   }
   std::cout << std::endl; 

}