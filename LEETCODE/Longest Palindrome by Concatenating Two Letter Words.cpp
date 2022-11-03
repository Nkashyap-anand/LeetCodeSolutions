class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {

        map<string, int> mp;

        int len = 0;
        int ans = 0;
        bool flag = false;

        for (auto ch : words)
        {
            mp[ch]++;
        }

        for (auto it : mp)
        {
            if (it.first[0] == it.first[1])
            {
                if (it.second % 2 == 1)
                {
                    flag = true;
                    len += it.second - 1;
                }
                else
                {
                    len += mp[it.first];
                }
                mp.erase(it.first);
            }

            else
            {
                string str = it.first;
                reverse(str.begin(), str.end());
                if (mp.find(str) != mp.end())
                {
                    ans += min(mp[str], it.second) * 4;
                }
                mp.erase(str);
                mp.erase(it.first);
            }
        }

        if (flag)
        {
            return ans + len * 2 + 2;
        }
        return ans + len * 2;
    }
};