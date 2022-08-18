class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {

        map<int, int> map;
        for (int i : arr)
            map[i]++;

        // reverse the ordering->frequency first, key->desc order
        multimap<int, int, greater<int>> mm;
        for (auto it : map)
        {
            mm.insert({it.second, it.first});
        }

        int n = arr.size();
        int sum = n;
        int count = 0;

        for (auto it = mm.begin(); it != mm.end(); it++)
        {
            sum -= it->first;
            count++;
            if (sum <= n / 2)
                return count;
        }
        return count;
    }
};