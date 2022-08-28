class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        int x, y, counter;

        // along the column
        for (int i = 0; i < m; i++)
        {
            vector<int> val;
            x = i;
            y = 0;

            while (x < m && y < n)
            {
                val.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(val.begin(), val.end());
            x = i;
            y = 0;
            counter = 0;
            while (x < m && y < n)
            {
                mat[y][x] = val[counter];
                x++;
                y++;
                counter++;
            }
        }

        // along the row
        for (int i = 1; i < n; i++)
        {
            vector<int> val;
            x = 0;
            y = i;

            while (x < m && y < n)
            {
                val.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(val.begin(), val.end());
            x = 0;
            y = i;
            counter = 0;
            while (x < m && y < n)
            {
                mat[y][x] = val[counter];
                x++;
                y++;
                counter++;
            }
        }
        return mat;
    }
};