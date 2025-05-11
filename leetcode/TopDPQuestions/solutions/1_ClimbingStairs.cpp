/**
 * Question: https://leetcode.com/problems/climbing-stairs/
 * Language: C++
 */


#include <bits/stdc++.h>
using namespace std;


int climbStairs(int n) {
    int lastThreeSteps[] = {0, 1, 1};
    for (int i = 1; i < n; i++) {
        lastThreeSteps[2] += lastThreeSteps[1];
        lastThreeSteps[1] += lastThreeSteps[0];
        lastThreeSteps[0] = lastThreeSteps[1] - lastThreeSteps[0];
    }
    return lastThreeSteps[2];
}
