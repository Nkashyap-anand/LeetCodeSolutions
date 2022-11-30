class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {

        map<int, int> m;

        for (auto it : arr)
        {
            m[it]++;
        }

        set<int> s;

        for (auto it : m)
        {
            if (s.count(it.second))
                return false;

            s.insert(it.second);
        }
        return true;
    }
};