// * @param 88. Merge Sorted Array // 

// * @param You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// * @param Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// * @param The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // int mid = m + (n - m) / 2; 
        // int nleft = mid - m + 1;
        // int nright = n - mid; 

        // int* left = new int[nleft];
        // int* right = new int[nright];

        // for (size_t i = 0; i < nleft; ++i) {
        //     left[i] = nums1[nleft + i];
        // }
        // for (size_t j = 0; j < nright; ++j) {
        //     right[j] = nums1[mid + j + 1];
        // }

        // int i = 0 , j = 0 , k = nleft;
        // while ((i < nleft) && (j < nright)) {
        //     if (left[i] <= right[j]) {
        //         nums1[k] = left[i];
        //         ++i;
        //     }
        //     else {
        //         nums1[k] = right[j];
        //         ++j;
        //     }
        //     ++k;
        // }

        // while (i < nleft) {
        //     nums1[k] = left[i];
        //     ++i;
        //     ++k;
        // }
        // while (j < nright) {
        //     nums1[k] = right[j];
        //     ++j;
        //     ++k;
        // }

        // int nmid = m + (n - m) / 2; 
        // int nleft1 = nmid - m + 1;
        // int nright1 = n - nmid; 

        // int* nlefti = new int[nleft1]; 
        // int* nrighti = new int[nright1];

        // for (size_t i = 0; i < nleft1; ++i) {
        //     nlefti[i] = nums2[nleft1 + i];
        // }

        // for (size_t j = 0; j < nright1; ++j) {
        //     nrighti[j] = nums2[nmid + j + 1];
        // }

        // int ii = 0 , jj = 0 , kk = 0;

        // while((ii < nleft1) && (jj < nright1)) {
        //     if (nlefti[ii] <= nrighti[jj]) {
        //      nums2[kk] = nlefti[ii];
        //         ++ii;
        //         ++kk;
        //    }
        //    else {
        //       nums2[kk] = nrighti[jj];
        //         ++jj;
        //         ++kk;
        //     }
        // }

        // while (ii < nleft1) {
        //     nums2[kk] = nlefti[ii];
        //     ++ii;
        //     ++kk;
        // }

        // while (jj < nright1) {
        //     nums2[kk] = nrighti[jj];
        //     ++jj;
        //     ++kk;
        // }

        //  delete[] right; 
        // right = nullptr; 
        // nright = 0; 
        // delete[] left; 
        // left = nullptr;
        // nleft = 0;

        // delete[] nrighti;
        // nrighti = nullptr; 
        // nright1 = 0;
        // delete[] nlefti;
        // nlefti = nullptr; 
        // nleft1 = 0;

        for (int j = 0 , i = m; j < n; ++j) {
            nums1[i] = nums2[j];
            ++i;
        }
        std::sort(nums1.begin() , nums1.end());
    }
};