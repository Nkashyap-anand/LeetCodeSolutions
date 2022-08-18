class Solution
{
public:
    int solve(vector<int> &nums, int val)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= val)
                count++;
        }
        return count;
    }

    int specialArray(vector<int> &nums)
    {
        int l = 0, r = nums.size();

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int comp = solve(nums, mid);

            if (comp == mid)
                return comp;
            else if (comp < mid)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
};