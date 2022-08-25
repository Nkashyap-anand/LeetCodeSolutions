class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {

        map<char, int> m;

        for (auto c : ransomNote)
            m[c]++;
        for (auto c : magazine)
            m[c]--;

        for (int i = 0; i < size(ransomNote); i++)
        {
            if (m[ransomNote[i]] > 0)
                return false;
        }

        return true;
    }
};