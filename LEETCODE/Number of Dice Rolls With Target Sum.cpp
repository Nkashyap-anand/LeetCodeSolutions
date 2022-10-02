// recursive solution

class Solution
{
public:
    int solve(int n, int k, int target)
    {
        if (target < 0)
            return 0;

        if ((n == 0 && target != 0) || (n != 0 && target == 0))
            return 0;

        if (n == 0 && target == 0)
            return 1;

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = ans + solve(n - 1, k, target - i);
        }

        int mod = 1e+7;
        return ans % mod;
    }

    int numRollsToTarget(int n, int k, int target)
    {

        return solve(n, k, target);
    }
};

// dp solution

class Solution
{
public:
#define mod 1000000007

    int solve(int n, int k, int target, vector<vector<long long>> &dp)
    {
        if (target < 0)
            return 0;

        if ((n == 0 && target != 0) || (n != 0 && target == 0))
            return 0;

        if (n == 0 && target == 0)
            return 1;

        if (dp[n][target] != -1)
            return dp[n][target];

        size_t ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = ans + solve(n - 1, k, target - i, dp);
            ans = ans % mod;
        }

        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target)
    {

        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};