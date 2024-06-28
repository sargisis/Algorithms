#include <iostream>
#include <chrono>
#include <vector>

using std::vector; 


// * @param Merge sort algorithm // 

void merge_sort_algorithm(vector<int>& arr, int start, int mid, int end) {
    int nleft = mid - start + 1;
    int nright = end - mid;


    vector<int> left(nleft);
    vector<int> right(nright);

    for (int i = 0; i < nleft; ++i) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < nright; ++j) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;
    while ((i < nleft) && (j < nright)) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i = i + 1;
        } else {
            arr[k] = right[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < nleft) {
        arr[k] = left[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < nright) {
        arr[k] = right[j];
        j = j + 1;
        k = k + 1;
    }
}

// * @param merge array // 

void merge_sort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int mid = p + (r - p) / 2;
        merge_sort(arr, p, mid);
        merge_sort(arr, mid + 1, r);
        merge_sort_algorithm(arr, p, mid, r);
    }
}

void print(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {1,000,0,2,3,4,57,42,45,66,3,23,1,1,1,2,3,45,7,8};

    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    print(arr);

    std::cout << "Merge sort taken " << elapsed.count() << "miliseconds" << std::endl; 

    return 0;
}
