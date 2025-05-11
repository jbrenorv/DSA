/**
 * Question: https://leetcode.com/problems/palindrome-partitioning-ii
 * Language: C++
 */


#include <bits/stdc++.h>
using namespace std;


#define INF 3000


int minCut(string s) {
    int n = s.size();
    vector<vector<int>> palindromes = getPalindromes(n, s);
    vector<int> dp(n + 1, INF);
    dp[n] = -1;
    for (int i = n - 1; i >= 0; i--)
        for (int j : palindromes[i])
            dp[i] = min(dp[i], 1 + dp[j + 1]);
    return dp[0];
}

vector<vector<int>> getPalindromes(int n, string& s) {
    vector<vector<int>> palindromes(n, vector<int>());
    for (int k = 0; k < n; k++) {
        // odd-lenght palindromes with k in the middle
        palindromes[k].push_back(k);
        int i = k - 1, j = k + 1;
        while (i >= 0 && j < n && s[i] == s[j])
            palindromes[i--].push_back(j++);
        
        // even-lenght palindromes with k and k+1 in the middle
        i = k, j = k + 1;
        while (i >= 0 && j < n && s[i] == s[j])
            palindromes[i--].push_back(j++);
    }
    return palindromes;
}
