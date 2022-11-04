class Solution
{
public:
    bool isVowel(char c)
    {
        char currCh = tolower(c);
        if (currCh == 'a' || currCh == 'e' || currCh == 'i' || currCh == 'o' || currCh == 'u')
            return true;
        return false;
    }

    string reverseVowels(string s)
    {

        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            bool leftCh = isVowel(s[left]);
            bool rightCh = isVowel(s[right]);

            if (leftCh && rightCh)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            if (!leftCh)
                left++;
            if (!rightCh)
                right--;
        }
        return s;
    }
};