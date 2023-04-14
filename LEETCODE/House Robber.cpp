// Recursive(TLE)
class Solution
{
public:
    int solve(int id, vector<int> &nums, vector<int> &dp)
    {
        if (id == 0)
            return nums[id];
        if (id < 0)
            return 0;

        int pick = nums[id] + solve(id - 2, nums, dp);
        int notPick = 0 + solve(id - 1, nums, dp);

        return max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(n - 1, nums, dp);
    }
};

// Memoization
class Solution
{
public:
    int solve(int id, vector<int> &nums, vector<int> &dp)
    {
        if (id == 0)
            return nums[id];
        if (id < 0)
            return 0;
        if (dp[id] != -1)
            return dp[id];
        int pick = nums[id] + solve(id - 2, nums, dp);
        int notPick = 0 + solve(id - 1, nums, dp);

        return dp[id] = max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(n - 1, nums, dp);
    }
};

// Tabulation
class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];
            int notTake = 0 + dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};

// Space optimized
class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;
        int curr;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int notTake = 0 + prev1;

            curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};