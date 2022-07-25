// binary search
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int id1 = lower_bond(nums, target);
        int id2 = lower_bond(nums, target + 1) - 1;

        if (id1 < nums.size() && nums[id1] == target)
            return {id1, id2};
        else
            return {-1, -1};
    }

    int lower_bond(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};

// stl functions
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (start >= nums.size() || nums[start] != target)
            return {-1, -1};
        return {start, end - 1};
    }
};