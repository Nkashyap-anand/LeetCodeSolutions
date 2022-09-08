// Just remove balanced parts from string because they won't help us.
// Put unbalanced halfs in stack.
// In the end you will be left with unmatched halfs only.

class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> st;

        for (char &ch : s)
        {
            if (ch == '[')
                st.push(ch);
            else if (!st.empty())
                st.pop();
        }
        return (st.size() + 1) / 2;
    }
};