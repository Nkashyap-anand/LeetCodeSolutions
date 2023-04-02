// recursive
class Solution
{
public:
    int climbStairs(int n)
    {

        if (n <= 1)
            return 1;

        int left = climbStairs(n - 1);
        int right = climbStairs(n - 2);

        return left + right;
    }
};

// memoization
class Solution
{
public:
    int climbStairs(int n)
    {

        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
};

// tabulation
class Solution
{
public:
    int climbStairs(int n)
    {

        if (n <= 1)
            return 1;

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// space optimized
class Solution
{
public:
    int climbStairs(int n)
    {

        if (n <= 1)
            return 1;

        int prev2 = 1;
        int prev1 = 1;

        for (int i = 2; i <= n; ++i)
        {
            int curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};