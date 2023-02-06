class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};

// space optimised
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {

        int j = n;

        for (int i = 1; i <= 2 * n; i += 2, j += 2)
            nums.insert(nums.begin() + i, nums[j]);

        nums.resize(2 * n);

        return nums;
    }
};