class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        for (int j = 0; j < s.length() + 1; j++)
        {
            if (s[j] == ' ' || j == s.length())
            {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        return s;
    }
};