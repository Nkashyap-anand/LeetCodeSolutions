class Solution
{
public:
    bool check(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0;
        int second = 0;

        while (first < s1.size())
        {
            if (s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        if (first == s1.size() && second == s2.size())
            return true;
        return false;
    }

    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &words)
    {

        int n = words.size(), maxi = 1;
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), comp);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (check(words[i], words[j]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }

            if (maxi < dp[i])
                maxi = dp[i];
        }
        return maxi;
    }
};