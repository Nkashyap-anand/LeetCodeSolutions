class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {

        priority_queue<int> pq;
        int max_reach = startFuel;
        int count = 0;
        int id = 0;

        while (max_reach < target)
        {
            while (id < stations.size() && stations[id][0] <= max_reach)
            {
                pq.push(stations[id][1]); // fuel
                id++;
            }
            if (pq.empty())
                return -1;
            max_reach += pq.top();
            pq.pop();
            count++;
        }

        return count;
    }
};