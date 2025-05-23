/**
 * Question: https://leetcode.com/problems/unique-binary-search-trees
 * Language: C++
 */


#include <bits/stdc++.h>
using namespace std;


int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] += dp[i - j] * dp[j - 1];
    return dp[n];
}
