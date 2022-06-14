class Solution
{
public:
    vector<vector<int>> ans;

    void subset(int idx, vector<int> &nums, vector<int> &temp)
    {
        if (idx == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        subset(idx + 1, nums, temp);
        temp.pop_back();
        subset(idx + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<int> temp;
        subset(0, nums, temp);
        return ans;
    }
};