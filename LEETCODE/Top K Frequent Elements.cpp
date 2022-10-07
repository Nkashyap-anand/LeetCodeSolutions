class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        map<int, int> m;
        vector<int> v;
        priority_queue<pair<int, int>> pq;

        for (int num : nums)
        {
            m[num]++;
        }

        for (auto it : m)
        {
            pq.push(make_pair(it.second, it.first));
            if (pq.size() > m.size() - k)
            {
                v.push_back(pq.top().second);
                pq.pop();
            }
        }
        return v;
    }
};