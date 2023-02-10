class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {

        int n = grid.size();
        deque<pair<int, int>> q;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                    q.push_back({i, j});
            }
        }

        int res = -1;
        vector<vector<int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop_front();
            res = grid[r][c];

            for (int i = 0; i < dir.size(); ++i)
            {
                int newR = r + dir[i][0];
                int newC = c + dir[i][1];

                if (min(newR, newC) >= 0 && max(newR, newC) < n &&
                    grid[newR][newC] == 0)
                {
                    q.push_back({newR, newC});
                    grid[newR][newC] = grid[r][c] + 1;
                }
            }
        }

        return res > 1 ? res - 1 : -1;
    }
};