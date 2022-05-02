class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {

        int j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] & 1) == 0)
            {
                swap(nums[j], nums[i]);
                ++j;
            }
        }
        return nums;
    }
};