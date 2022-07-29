// recursion (TLE)

class Solution
{
public:
    int find(int i, int j)
    {
        // edge cases
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 or j < 0)
            return 0;

        int up = find(i - 1, j);   // moving up is possible
        int left = find(i, j - 1); //// moving left is possible

        return (up + left);
    }

    int uniquePaths(int m, int n)
    {
        return find(m - 1, n - 1);
    }
};

// dp

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        // edge cases
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        // if already encountered and stored in dp
        if (dp[i][j] != -1)
            return dp[i][j];

        // visiting for 1st time
        dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);

        return dp[i][j];
    }

    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, dp);
    }
};