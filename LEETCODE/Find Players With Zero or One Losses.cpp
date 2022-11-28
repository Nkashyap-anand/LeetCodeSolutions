class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {

        map<int, int> m;

        for (int i = 0; i < matches.size(); ++i)
        {
            m[matches[i][1]]++;
        }

        vector<vector<int>> ans;
        vector<int> temp;

        for (int i = 0; i < matches.size(); ++i)
        {
            if (m.find(matches[i][0]) == m.end())
            {
                temp.push_back(matches[i][0]);
                m[matches[i][0]] = 2;
            }
        }
        sort(temp.begin(), temp.end());

        ans.push_back(temp);

        temp.clear();

        for (auto it : m)
        {
            if (it.second == 1)
                temp.push_back(it.first);
        }

        ans.push_back(temp);

        return ans;
    }
};