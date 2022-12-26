class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int index = nums.size() - 1;

        for (int i = index; i >= 0; i--)
        {
            if (i + nums[i] >= index)
                index = i;
        }

        if (index == 0)
            return true;
        return false;
    }
};