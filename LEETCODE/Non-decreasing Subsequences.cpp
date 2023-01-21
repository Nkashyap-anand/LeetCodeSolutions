class Solution
{
public:
    set<vector<int>> ans;
    void solve(int start, int n, vector<int> &nums, vector<int> &res)
    {
        if (res.size() > 1)
            ans.insert(res);
        if (start == n)
            return;

        for (int i = start; i < n; ++i)
        {
            if (res.empty() || res.back() <= nums[i])
            {
                res.push_back(nums[i]);
                solve(i + 1, n, nums, res);
                res.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> res;
        solve(0, n, nums, res);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};