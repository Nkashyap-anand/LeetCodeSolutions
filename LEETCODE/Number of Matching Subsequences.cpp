// bruteforce soln

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;

        for (auto x : words)
        {
            int i = 0, j = 0;

            while (i < s.size() && j < x.size())
            {
                if (s[i] == x[j])
                {
                    j++;
                }
                i++;
            }
            if (j == x.size())
                count++;
        }
        return count;
    }
};

// optimized soln

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {

        int count = words.size();
        vector<vector<int>> charIndex(26);

        for (int i = 0; i < s.size(); i++)
        {
            charIndex[s[i] - 'a'].push_back(i);
        }

        for (auto &word : words)
        {
            int lastIndex = -1;

            for (auto w : word)
            {
                auto &charIndexArr = charIndex[w - 'a'];
                auto index = upper_bound(charIndexArr.begin(), charIndexArr.end(), lastIndex);

                if (index == charIndexArr.end())
                {
                    count--;
                    break;
                }
                else
                {
                    lastIndex = *index;
                }
            }
        }
        return count;
    }
};