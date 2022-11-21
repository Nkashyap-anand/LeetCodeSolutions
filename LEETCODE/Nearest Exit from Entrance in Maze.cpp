class Solution
{
public:
    vector<int> rowDir = {-1, 1, 0, 0};
    vector<int> colDir = {0, 0, -1, 1};

    bool validStep(vector<vector<char>> &maze, int newRow, int newCol)
    {
        if (newRow < 0 || newCol < 0 || newRow == maze.size() || newCol == maze[0].size() || maze[newRow][newCol] == '+')
            return false;

        return true;
    }

    bool border(vector<vector<char>> &maze, int newRow, int newCol)
    {
        if (newRow == 0 || newRow == maze.size() - 1)
            return true;
        if (newCol == 0 || newCol == maze[0].size() - 1)
            return true;

        return false;
    }

    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        int path = 0;
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; ++dir)
                {
                    int newRow = row + rowDir[dir];
                    int newCol = col + colDir[dir];

                    if (validStep(maze, newRow, newCol))
                    {
                        maze[newRow][newCol] = '+';
                        if (border(maze, newRow, newCol))
                        {
                            return path + 1;
                        }
                        else
                            q.push({newRow, newCol});
                    }
                }
            }
            path++;
        }
        return -1;
    }
};