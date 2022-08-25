class Solution
{
public:
    int myAtoi(string s)
    {

        if (s.length() == 0)
            return 0;

        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;

        s = s.substr(i); // take substring from ith index to last

        int sign = +1;
        long ans = 0;

        if (s[0] == '-')
            sign = -1;

        int Max = INT_MAX, Min = INT_MIN;

        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        while (i < s.length())
        {
            if (s[0] == ' ' || !isdigit(s[i]))
                break;
            ans = ans * 10 + s[i] - '0';

            if (sign == -1 && -1 * ans < INT_MIN)
                return Min;
            if (sign == 1 && ans > INT_MAX)
                return Max;

            i++;
        }
        return (int)sign * ans;
    }
};