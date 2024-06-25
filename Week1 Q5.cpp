/*Question:
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        
        for (int price : prices) {
            min_price = std::min(min_price, price);
            int potential_profit = price - min_price;
            max_profit = std::max(max_profit, potential_profit);
        }
        return max_profit;
    }
};