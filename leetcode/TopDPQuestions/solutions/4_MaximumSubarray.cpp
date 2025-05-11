/**
 * Question: https://leetcode.com/problems/maximum-subarray
 * Language: C++
 */


#include <bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {
    int answer = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] = max(nums[i], nums[i] + nums[i - 1]);
        answer = max(answer, nums[i]);
    }
    return answer;
}
