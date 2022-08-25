// using stack
class Solution
{
public:
    int longestValidParentheses(string s)
    {

        stack<int> st;
        st.push(-1);
        int maxl = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);

            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxl = max(maxl, i - st.top());
                }
            }
        }
        return maxl;
    }
};

// two pointer
class Solution
{
public:
    int longestValidParentheses(string s)
    {

        int open = 0, close = 0, maxl = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (close == open)
                maxl = max(maxl, 2 * open);
            else if (close >= open)
            {
                open = 0;
                close = 0;
            }
        }

        open = 0, close = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (close == open)
                maxl = max(maxl, 2 * open);
            else if (close <= open)
            {
                open = 0;
                close = 0;
            }
        }
        return maxl;
    }
};