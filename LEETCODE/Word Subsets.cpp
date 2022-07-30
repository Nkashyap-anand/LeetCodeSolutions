class Solution
{
public:
    vector<int> counter(string &s)
    {
        vector<int> count(26);

        for (char c : s)
            count[c - 'a']++;
        return count;
    }

    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {

        int n = B.size();
        vector<string> ans;
        vector<int> countMax(26, 0);

        for (auto c : B)
        {
            vector<int> temp = counter(c);

            for (int i = 0; i < 26; i++)
            {
                countMax[i] = max(countMax[i], temp[i]);
            }
        }

        for (auto c : A)
        {
            vector<int> temp = counter(c);
            int i;

            for (i = 0; i < 26; i++)
            {
                if (temp[i] < countMax[i])
                    break;
            }
            if (i == 26)
                ans.push_back(c);
        }
        return ans;
    }
};