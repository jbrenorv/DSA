/**
 * Question: https://leetcode.com/problems/fibonacci-number
 * Language: C++
 */


#include <bits/stdc++.h>
using namespace std;


int fib(int n) {
    int Fn = 1, Fn_1 = 0;
    for (int i = 2; i <= n; i++) {
        Fn += Fn_1;
        Fn_1 = Fn - Fn_1;
    }
    return (n == 0 ? 0 : Fn);
}
