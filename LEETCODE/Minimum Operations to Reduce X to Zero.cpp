class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        int totalSum = 0;
        for (auto i : nums)
            totalSum += i;

        int windowSum = totalSum - x;

        int currSum = 0, n = nums.size(), i = 0, maxLen = 0;

        bool found = false;

        for (int j = 0; j < n; j++)
        {
            currSum += nums[j];

            while (i <= j && currSum > windowSum)
            {
                currSum -= nums[i];
                i++;
            }
            if (currSum == windowSum)
            {
                found = true;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return found ? (n - maxLen) : -1;
    }
};