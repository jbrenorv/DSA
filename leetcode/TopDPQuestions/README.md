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

We need to check the cheaper stock in the subarray $prices[0..i-1]$. But how can we do that efficiently?
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

## [3. House Robber](https://leetcode.com/problems/house-robber/description/)

<details>
<summary>Hint 1</summary>

Try to reduce the original problem to a smaller one.
</details>

<details>
<summary>Hint 2</summary>

Think about recursion.
</details>

<details>
<summary>Hint 3</summary>

Imagine that you have the optimal solutions for all prefixes up to $i-1$.
How can you use that information to find the optimal solution for the prefix $nums[0..i]$?
</details>

<details>
<summary>Follow up</summary>

The time and memory complexity of your solution should be $O(n)$ and $O(1)$, respectively.
</details>

<details>
<summary>Solution</summary>

Let $previousAnswer$ and $answer$ be the optimal solutions for the prefixes $nums[0..i-2]$ and $nums[0..i-1]$, respectively.

All we need to do is keep this relationship true throughout all iterations of our algorithm.

In the $i^{th}$ iteration, the optimal solution for the prefix $nums[0..i]$ is given by $max(answer,\ nums[i] + previousAnswer)$.

In other words, it's basically a decision: rob the $i^{th}$ house or not.

```cpp
int rob(vector<int>& nums) {
    int temp, previousAnswer = 0, answer = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        temp = answer;
        answer = max(answer, nums[i] + previousAnswer);
        previousAnswer = temp;
    }
    return answer;
}
```
</details>
