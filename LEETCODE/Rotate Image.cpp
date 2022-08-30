// approach 1
class Solution
{
public:
    void rotate(vector<vector<int>> &m)
    {

        int n = m.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(m[i][j], m[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(m[i].begin(), m[i].end());
        }
    }
};

// approach 2
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int a = 0;
        int b = matrix.size() - 1;

        while (a < b)
        {
            for (int i = 0; i < (b - a); i++)
            {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            ++a;
            --b;
        }
    }
};