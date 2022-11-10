class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (!ans.empty())
            {
                if (ans.back() == s[i])
                {
                    ans.pop_back();
                }
                else
                {
                    ans.push_back(s[i]);
                }
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};