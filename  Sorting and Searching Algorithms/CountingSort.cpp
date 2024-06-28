#include <iostream>
#include <vector>
#include <chrono>

using std::vector;
// * @param counting sort algorithm // 

vector<int> counting_sort_algorithm(vector<int>& arr) {
    int N = arr.size(); 

    int MaxNumber = 0; 
    
    for (size_t i = 0; i < N; ++i) {
        MaxNumber = std::max(MaxNumber, arr[i]);
    }

   vector<int> count_array(MaxNumber + 1 , 0);
   
   for (int i = 0; i < N; ++i) {
        count_array[arr[i]]++;
   }

    for (int i = 1; i <= MaxNumber; ++i) {
        count_array[i] += count_array[i - 1];
    }

    vector<int> output_array(N);

    for (int i = N - 1; i >= 0; --i) {
      output_array[count_array[arr[i]] - 1] = arr[i];
       count_array[arr[i]]--;
    }

    return output_array;
}

void print(vector<int>& arr) 
{
    for (size_t i = 0; i < arr.size(); ++i) 
    {
        std::cout << arr[i] << " ";
    }
}

int main() {
   
   vector<int> arr = {2,5,3,0,2,3,0,3};

   auto start = std::chrono::high_resolution_clock::now();
   vector<int> output_array = counting_sort_algorithm(arr);
   auto end = std::chrono::high_resolution_clock::now();

   std::chrono::duration<double> elapsed = end - start;

   print(arr);
   std::cout << "Counting sort taken " << elapsed.count() << "miliseconds" << std::endl;
}