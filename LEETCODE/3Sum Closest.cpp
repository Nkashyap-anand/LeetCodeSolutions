class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());
        int sum = 0;
        int ans = 0;
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end)
            {
                sum = nums[i] + nums[start] + nums[end];

                if (abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    ans = sum;
                }

                if (sum == target)
                    return target;

                else if (sum < target)
                    start++;

                else
                    end--;
            }
        }
        return ans;
    }
};