// easy approach
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {

        vector<int> sortedNums(nums);
        int start = nums.size();
        int end = 0;
        sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != sortedNums[i])
            {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return (end - start >= 0 ? end - start + 1 : 0);
    }
};

// without extra space
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {

        int i = 0, j = nums.size() - 1, Min, Max;

        // moving i to first unsorted elm
        while (i < j && nums[i] <= nums[i + 1])
            i++;

        // moving j to last unsorted elm
        while (i < j && nums[j] >= nums[j - 1])
            j--;

        // if already sorted
        if (i == j)
            return 0;

        Min = nums[i], Max = nums[j];

        for (int k = i; k <= j; k++)
        {
            Min = min(Min, nums[k]);
            Max = max(Max, nums[k]);
        }

        if (Min < nums[i])
            i = upper_bound(begin(nums), begin(nums) + i, Min) - begin(nums);
        if (Max > nums[j])
            j = lower_bound(begin(nums) + j, end(nums), Max) - begin(nums);

        return j - i;
    }
};