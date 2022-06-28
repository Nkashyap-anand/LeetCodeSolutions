class Solution
{
public:
    int minDeletions(string s)
    {

        vector<int> v(26, 0);

        for (auto c : s)
        {
            v[c - 'a']++;
        }

        sort(v.begin(), v.end(), greater<int>());

        int maxFreq = v[0];
        int ans = 0;

        for (auto i : v)
        {
            if (i > maxFreq)
            {
                if (maxFreq > 0)
                    ans += (i - maxFreq);
                else
                    ans += i;
            }
            maxFreq = min(maxFreq - 1, i - 1);
        }
        return ans;
    }
};