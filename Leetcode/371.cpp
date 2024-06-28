#include <iostream>

using namespace std; 

// * @param 371. Sum of Two Integers

// * @param Given two integers a and b, return the sum of the two integers without using the operators + and -.

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
        {
            return a;
        }
        int sum = a ^ b; 
        int carry = (a & b) << 1; 
        return getSum(sum , carry);
    }
};