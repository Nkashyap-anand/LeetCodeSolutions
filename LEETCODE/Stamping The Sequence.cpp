class Solution
{
public:
    // get the index of the string as the answer
    int check(string &str, string stamp)
    {
        int n = str.length();

        for (int i = 0; i < n; i++)
        {
            int j = 0, tmp = i;
            bool flag = false;

            // iterate upto stamps length and check if we have a stamping possible?
            while (j < stamp.length() && tmp < n && (str[tmp] == '*' || str[tmp] == stamp[j]))
            {
                // if there is a stamping
                // flag = true
                if (str[tmp] == stamp[j])
                    flag = true;

                // increment temp and j each time
                tmp++;
                j++;
            }

            // if there exists any valid index where we can do stamping

            if (j == stamp.length() && flag)
            {
                // change the string str
                for (int k = 0; k < stamp.length(); k++)
                {
                    str[i + k] = '*';
                }
                return i;
            }
        }
        return n;
    }

    vector<int> movesToStamp(string stamp, string target)
    {

        vector<int> ans, result;
        string str = target;
        string ff(target.length(), '*');

        // iterate till we haven't have str containing only '*'
        while (str != ff)
        {
            // check if still we need to do stamping?
            int value = check(str, stamp);

            // if done return result
            if (value == str.length())
                return result;

            ans.push_back(value);
        }

        // reverse the answer to store it in result finally
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            result.push_back(ans[i]);
        }
        return result;
    }
};