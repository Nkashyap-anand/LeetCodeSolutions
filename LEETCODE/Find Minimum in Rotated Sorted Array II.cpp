class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int l = 0, r = nums.size() - 1, mid = 0;

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else
            {
                r--;
            }
        }
        return nums[mid];
    }
};