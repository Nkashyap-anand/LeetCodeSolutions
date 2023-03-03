class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        int n = haystack.size();
        int m = needle.size();

        if (haystack == needle)
            return 0;

        for (int i = 0; i < n - m + 1; i++)
        {
            if (haystack[i] == needle[0])
            {
                if (haystack.substr(i, m) == needle.substr(0, m))
                    return i;
            }
        }
        return -1;
    }
};