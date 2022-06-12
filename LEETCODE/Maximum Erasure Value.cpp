class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {

        int currSum = 0, ans = 0;
        unordered_set<int> set;

        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            while (set.find(nums[j]) != set.end())
            {
                set.erase(nums[i]);
                currSum -= nums[i];
                i++;
            }
            set.insert(nums[j]);
            currSum += nums[j];
            ans = max(currSum, ans);
        }
        return ans;
    }
};