class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 1)
            return true;
        int id = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (id != 0)
                    return false;
                id = i;
            }
        }

        if (id == 0 || id == 1 || id == n - 1)
            return true;
        if (nums[id - 1] > nums[id + 1] && nums[id - 2] > nums[id])
            return false;

        return true;
    }
};