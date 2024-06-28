#include <iostream>
#include <vector>
#include <chrono>

using std::vector;


// * @param special for radix sort // 

int get_max(vector<int>& arr)  
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;   
}

// * @param counting sort algorithm special for radix sort // 

void counting_sort_algorithm(vector<int>& arr , int expr) 
{
    size_t N = arr.size();

    vector<int> output_array(N);
    int count_array[10] = {0};

    for (int i = 0; i < N; ++i) {
        count_array[(arr[i] / expr) % 10]++;
    } 

    for (int i = 1; i < 10; ++i) {
        count_array[i] += count_array[i - 1];
    }

    for (int i = N - 1; i >= 0; --i) {
        output_array[count_array[(arr[i] / expr) % 10] - 1] = arr[i];
        count_array[(arr[i] / expr) % 10]--;
    }

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output_array[i];
    }
}

// * @param radix sort algorithm // 

void radix_sort_algorithm(vector<int>& arr) 
{
    int m = get_max(arr);

    for (int expr = 1; m / expr > 0; expr*= 10) 
    {
        counting_sort_algorithm(arr,expr);
    }
} 

void print(vector<int>& arr) 
{
    for (size_t i = 0; i < arr.size(); ++i) 
    {
        std::cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {6,4,3,524,2,52,35,67, 4,4 , 4, 42,2 ,32 ,2,23,4,23423};

    auto start = std::chrono::high_resolution_clock::now();
    radix_sort_algorithm(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr);
    std::cout << "Time taken Radix sort " << elapsed.count() << "miliseconds" << std::endl; 

}