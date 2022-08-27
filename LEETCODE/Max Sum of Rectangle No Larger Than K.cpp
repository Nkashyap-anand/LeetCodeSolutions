class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &m, int k)
    {
        int res = INT_MIN, row = m.size(), col = m[0].size();

        for (int l = 0; l < col; l++)
        {
            vector<int> sums(row);

            for (int r = l; r < col; r++)
            {
                for (int i = 0; i < row; i++)
                    sums[i] += m[i][r];
                set<int> s = {0};
                int run_sum = 0;

                for (int sum : sums)
                {
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if (it != s.end())
                        res = max(res, run_sum - *it);
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};