// using extra space
class Solution
{
public:
    void solve(vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans, int freq[])
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                temp.push_back(nums[i]);
                freq[i] = 1;
                solve(temp, nums, ans, freq);
                freq[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;
        solve(temp, nums, ans, freq);
        return ans;
    }
};

// without using extra space
class Solution
{
public:
    void solve(int id, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (id == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = id; i < nums.size(); i++)
        {
            swap(nums[id], nums[i]);
            solve(id + 1, nums, ans);
            swap(nums[id], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};