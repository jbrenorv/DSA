# Top 40 Dynamic Programming Questions
Here I'll discuss my ideas and solutions for the questions from [this list](https://leetcode.com/discuss/post/4271883/top-dynamic-programming-questions-by-nin-rnr8/).

## [1. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

<details>
<summary>Hint 1</summary>

Maybe this is the first DP question that everyone sees. It's equivalent to finding the $n^{th}$ Fibonacci number.
</details>

<details>
<summary>Follow up</summary>

Many people will solve this problem using $O(n)$ extra memory. Can you solve it in $O(1)$?
</details>

<details>
<summary>Solution</summary>

```cpp
int climbStairs(int n) {
    int lastThreeSteps[] = {0, 1, 1};
    for (int i = 1; i < n; i++) {
        lastThreeSteps[2] += lastThreeSteps[1];
        lastThreeSteps[1] += lastThreeSteps[0];
        lastThreeSteps[0] = lastThreeSteps[1] - lastThreeSteps[0];
    }
    return lastThreeSteps[2];
}
```
</details>

## [2. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

<details>
<summary>Hint 1</summary>

Imagine you are on the $i^{th}$ day. Which of the previous stocks would you buy?
</details>

<details>
<summary>Hint 2</summary>

Yes! We need to check the cheaper stock in the subarray $prices[0..i-1]$. But how can we do that efficiently?
</details>

<details>
<summary>Solution</summary>

The answer is given by: $max(prices[i] - min(prices[0..i-1]))$

```cpp
int maxProfit(vector<int>& prices) {
    int answer = 0;
    int currentMinPrice = prices[0];
    for (int i = 0; i < (int) prices.size(); i++) {
        answer = max(answer, prices[i] - currentMinPrice);
        currentMinPrice = min(currentMinPrice, prices[i]);
    }
    return answer;
}
```
</details>
