class Solution
{
public:
    int solve(vector<int> &cost, int id, vector<int> &memo)
    {
        if (id == cost.size() - 1 || id == cost.size() - 2)
            return cost[id];

        if (memo[id] != 0)
            return memo[id];

        int x = solve(cost, id + 1, memo);
        int y = solve(cost, id + 2, memo);

        memo[id] = min(x, y) + cost[id];

        return memo[id];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {

        if (cost.size() == 2)
            return min(cost[0], cost[1]);

        vector<int> memo(1001);

        int x = solve(cost, 0, memo);
        int y = solve(cost, 1, memo);

        return min(x, y);
    }
};