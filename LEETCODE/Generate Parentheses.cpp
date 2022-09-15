class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {

        vector<string> ans;

        add(ans, "", n, 0);

        return ans;
    }

    void add(vector<string> &ans, string str, int n, int m)
    {
        if (n == 0 && m == 0)
            ans.push_back(str);

        if (m > 0)
        {
            add(ans, str + ")", n, m - 1);
        }
        if (n > 0)
        {
            add(ans, str + "(", n - 1, m + 1);
        }
    }
};