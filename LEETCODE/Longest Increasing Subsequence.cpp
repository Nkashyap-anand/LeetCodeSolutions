// recursize soln
class Solution
{
public:
    int solve(int id, int prev, vector<int> &nums)
    {

        if (id == nums.size())
            return 0;

        int len = solve(id + 1, prev, nums);

        if (prev == -1 || nums[id] > nums[prev])
        {
            len = max(len, 1 + solve(id + 1, id, nums));
        }
        return len;
    }

    int lengthOfLIS(vector<int> &nums)
    {

        return solve(0, -1, nums);
    }
};

// dp memoization
class Solution
{
public:
    int solve(int id, int prev, vector<int> &nums, vector<vector<int>> &dp, int n)
    {

        if (id == n)
            return 0;

        if (dp[id][prev + 1] != -1)
            return dp[id][prev + 1];

        int notTake = solve(id + 1, prev, nums, dp, n);
        int take = INT_MIN;

        if (prev == -1 || nums[id] > nums[prev])
        {
            take = 1 + solve(id + 1, id, nums, dp, n);
        }
        return dp[id][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp, n);
    }
};