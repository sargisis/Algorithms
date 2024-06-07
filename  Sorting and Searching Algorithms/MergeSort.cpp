#include <iostream>

void merge_sort_algorithm(int* arr, int start, int mid, int end) {
    int nleft = mid - start + 1;
    int nright = end - mid;


    int* left = new int[nleft];
    int* right = new int[nright];

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

    delete[] left;
    delete[] right;

}

void merge_sort(int* arr, int p, int r) {
    if (p < r) {
        int mid = p + (r - p) / 2;
        merge_sort(arr, p, mid);
        merge_sort(arr, mid + 1, r);
        merge_sort_algorithm(arr, p, mid, r);
    }
}

int main() {
    int arr[] = {1,000,0,2,3,4,57,42,45,66,3,23,1,1,1,2,3,45,7,8};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Sorting before " << std::endl; 
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    merge_sort(arr, 0, arr_size - 1);
    
    std::cout << "Sorting array with merge_sort" << std::endl; 
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

 
    return 0;
}
