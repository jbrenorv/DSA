/**
 * Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Language: C++
 */

#include <bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& prices) {
    int answer = 0;
    int currentMinPrice = prices[0];
    for (int i = 0; i < (int) prices.size(); i++) {
        answer = max(answer, prices[i] - currentMinPrice);
        currentMinPrice = min(currentMinPrice, prices[i]);
    }
    return answer;
}
