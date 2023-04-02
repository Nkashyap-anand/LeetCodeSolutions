// recursive solution
class Solution
{
public:
    int fib(int n)
    {

        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// memoization
class Solution
{
public:
    int fib(int n)
    {

        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }

    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
};

// tabulation
class Solution
{
public:
    int fib(int n)
    {

        if (n <= 1)
            return n;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// more space optimized
class Solution
{
public:
    int fib(int n)
    {

        if (n <= 1)
            return n;

        int prev2 = 0;
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