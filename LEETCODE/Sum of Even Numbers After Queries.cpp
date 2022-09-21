class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        vector<int> ret;
        int sum = 0;

        for (auto query : queries)
        {
            if (ret.size() == 0)
            {
                A[query[1]] = query[0] + A[query[1]];
                for (int a : A)
                    if (a % 2 == 0)
                        sum += a;
            }
            else
            {
                if (A[query[1]] % 2 == 0)
                    sum -= A[query[1]];
                A[query[1]] = query[0] + A[query[1]];
                if (A[query[1]] % 2 == 0)
                    sum += A[query[1]];
            }

            ret.push_back(sum);
        }

        return ret;
    }
};

/// brute force
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {

        int n = nums.size();
        vector<int> ans;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            int id = queries[i][1];

            nums[id] += queries[i][0];

            for (int j = 0; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                    sum += nums[j];
            }

            ans.push_back(sum);

            sum = 0;
        }
        return ans;
    }
};