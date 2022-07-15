class Solution
{
public:
    int count_island(vector<vector<int>> &grid, int i, int j, int &count)
    {
        // check for bounds
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;

        if (grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        // checking neighbours
        if (count_island(grid, i + 1, j, count))
            count++;
        if (count_island(grid, i - 1, j, count))
            count++;
        if (count_island(grid, i, j + 1, count))
            count++;
        if (count_island(grid, i, j - 1, count))
            count++;

        return 1;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        int Max = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 1;
                // check if value is 1
                if (grid[i][j])
                {
                    count_island(grid, i, j, count);
                    Max = max(count, Max);
                }
            }
        }
        return Max;
    }
};