// o(n) time o(n) space

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {

        int count = 0, cmp;

        map<int, int> m;

        for (auto i : nums)
        {
            cmp = k - i;

            if (m[cmp] > 0)
            {
                count++;
                m[cmp]--;
            }
            else
                m[i]++;
        }

        return count;
    }
};

// o(nlog(n)) time o(1) space

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {

        int count = 0, l = 0, r = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while (l < r)
        {
            int sum = nums[l] + nums[r];

            if (sum == k)
            {
                l++;
                r--;
                count++;
            }
            else if (sum < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return count;
    }
};