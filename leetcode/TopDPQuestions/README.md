# Top 40 Dynamic Programming Questions
Here I'll discuss my ideas and solutions for the questions from [this list](https://leetcode.com/discuss/post/4271883/top-dynamic-programming-questions-by-nin-rnr8/).

## [1. Climbing Stairs](https://leetcode.com/problems/climbing-stairs)

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

## [2. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock)

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

## [3. House Robber](https://leetcode.com/problems/house-robber)

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

## [4. Maximum Subarray](https://leetcode.com/problems/maximum-subarray)

<details>
<summary>Hint 1</summary>

What is the maximum sum among all subarrays that end at position $i - 1$?
</details>

<details>
<summary>Hint 2</summary>

Imagine you know the answer to the previous question.
How can you use it to answer the same question for position $i$?
</details>

<details>
<summary>Solution</summary>

Imagine we are at position $i$, and suppose we have already updated $nums[j]$ to be the maximum sum among all subarrays that end at position $j$, for all $0 \leq j < i$.

Then, to update $nums[i]$ with the same property, simply set $nums[i] = \max(\text{start a new sum}, \text{extend the previous sum})$.

After all, the answer will be $\max(\text{nums})$.

```cpp
int maxSubArray(vector<int>& nums) {
    int answer = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] = max(nums[i], nums[i] + nums[i - 1]);
        answer = max(answer, nums[i]);
    }
    return answer;
}
```
</details>

## [5. Fibonacci Number](https://leetcode.com/problems/fibonacci-number)

<details>
<summary>Hint 1</summary>

$F(n) = F(n - 1) + F(n - 2)$
</details>

<details>
<summary>Solution</summary>

```cpp
int fib(int n) {
    int Fn = 1, Fn_1 = 0;
    for (int i = 2; i <= n; i++) {
        Fn += Fn_1;
        Fn_1 = Fn - Fn_1;
    }
    return (n == 0 ? 0 : Fn);
}
```
</details>

## [6. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum)

<details>
<summary>Hint 1</summary>

Imagine you know the answer for starting at positions $(i, j + 1)$ and $(i + 1, j)$.
How can you use that to find the answer for starting at position $(i, j)$?
</details>

<details>
<summary>Hint 2</summary>

When you are in the last row, you can only move to the right.
Similarly, when you are in the last column, you can only move down.
</details>

<details>
<summary>Hint 3</summary>

Use two reverse for-loops to find the answer
</details>

<details>
<summary>Solution</summary>

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));

    dp[n - 1][m - 1] = grid[n - 1][m - 1];

    for (int i = m - 2; i >= 0; i--)
        dp[n - 1][i] = grid[n - 1][i] + dp[n - 1][i + 1];
    
    for (int i = n - 2; i >= 0; i--)
        dp[i][m - 1] = grid[i][m - 1] + dp[i + 1][m - 1];

    for (int i = n - 2; i >= 0; i--)
        for (int j = m - 2; j >= 0; j--)
            dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
    
    return dp[0][0];
}
```
</details>

## [7. Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii)

<details>
<summary>Hint 1</summary>

For every index $i$, determine all indices $j \geq i$ such that the substring $s[i..j]$ is a palindrome.
</details>

<details>
<summary>Hint 2</summary>

Create an auxiliary array called $dp$, where $dp[i]$ should be the answer for the problem applied to the suffix $s[i..n-1]$, and fill it from right to left.
</details>

<details>
<summary>Solution 1 O(n³)</summary>

```cpp
int minCut(string s) {
    int n = s.size();
    vector<vector<int>> palindromes(n, vector<int>());
    { // O(n^3)
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (isPalindrome(i, j, s))
                    palindromes[i].push_back(j);
    }
    vector<int> dp(n, INF);
    return minCut(0, n, dp, palindromes);
}

int minCut(int i, int n, vector<int>& dp, vector<vector<int>>& palindromes) {
    if (i >= n) return -1;
    if (dp[i] != INF) return dp[i];
    for (int j : palindromes[i]) {
        dp[i] = min(dp[i], 1 + minCut(j + 1, n, dp, palindromes));
    }
    return dp[i];
}

bool isPalindrome(int i, int j, string& s) {
    while (i < j) if (s[i++] != s[j--]) return false;
    return true;
}
```
</details>

<details>
<summary>Solution 2 O(n²)</summary>

```cpp
int minCut(string s) {
    int n = s.size();
    vector<vector<int>> palindromes(n, vector<int>());
    { // O(n^2)
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
    }
    vector<int> dp(n, INF);
    return minCut(0, n, dp, palindromes);
}

int minCut(int i, int n, vector<int>& dp, vector<vector<int>>& palindromes) {
    if (i >= n) return -1;
    if (dp[i] != INF) return dp[i];
    for (int j : palindromes[i]) {
        dp[i] = min(dp[i], 1 + minCut(j + 1, n, dp, palindromes));
    }
    return dp[i];
}

bool isPalindrome(int i, int j, string& s) {
    while (i < j) if (s[i++] != s[j--]) return false;
    return true;
}
```
</details>

<details>
<summary>Solution 3 O(n²) without recursion</summary>

```cpp
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
```
</details>

## [8. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees)

<details>
<summary>Hint 1</summary>

The answer is the same for every set of length $n$.
</details>

<details>
<summary>Hint 2</summary>

If you choose the node $i$ to be the root, how many nodes will be in the left subtree and the right subtree?
Think of the left and right subtrees as smaller instances of the same problem.
</details>

<details>
<summary>Follow up</summary>

If you find the recursive solution, try to implement an iterative one.
</details>

<details>
<summary>Solution 0 (math)</summary>

Let $f(n)$ be the number of structurally unique BSTs that have exactly $n$ nodes with distinct values from $1$ to $n$.

Additionally, let $g(i, n)$ denote the number of values greater than a given number $i$, and let $l(i, n)$ denote the number of values less than $i$.

Then, the following recurrence holds:

$f(n) = \sum_{i=1}^{n} f(g(i,n)) \cdot f(l(i,n))$
</details>

<details>
<summary>Solution 1 (recursive)</summary>

```cpp
int numTrees(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    return numTrees(n, dp);
}

int numTrees(int n, vector<int>& dp) {
    if (dp[n] != -1) return dp[n];
    int answer = 0;
    for (int i = n; i >= 1; i--) {
        int nGreater = n - i;
        int nLess = i - 1;
        answer += numTrees(nGreater, dp) * numTrees(nLess, dp);
    }
    return dp[n] = answer;
}
```
</details>

<details>
<summary>Solution 2 (iterative)</summary>

```cpp
int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] += dp[i - j] * dp[j - 1];
    return dp[n];
}
```
</details>
