class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        unordered_map<int, int> m;
        int sum = 0, ans = 0;
        m[0] = 1;

        for (auto i : nums)
        {
            sum = ((sum + i) % k + k) % k;
            m[sum]++;

            if (m[sum] > 1)
            {
                ans += m[sum] - 1;
            }
        }
        return ans;
    }
};