/**
 * Question: https://leetcode.com/problems/house-robber/
 * Language: C++
 */


#include <bits/stdc++.h>
using namespace std;


int rob(vector<int>& nums) {
    int temp, answer, previousAnswer;
    previousAnswer = 0;
    answer = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        temp = answer;
        answer = max(answer, nums[i] + previousAnswer);
        previousAnswer = temp;
    }
    return answer;
}
