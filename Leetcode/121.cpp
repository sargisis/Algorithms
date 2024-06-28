#include <iostream>

using namespace std; 

// * @param 121. Best Time to Buy and Sell Stock

// * @param You are given an array prices where prices[i] is the price of a given stock on the ith day.

// * @param You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// * @param Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = 0; 
        for (int i = 1; i < prices.size(); ++i)
        {
            min = min > prices[i] ? prices[i] : min;
            max = std::max(max , prices[i] - min);
        }
        return max; 
    }
};
