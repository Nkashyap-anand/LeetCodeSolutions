class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int n)
    {

        for (int i = 0; i < capacity.size(); i++)
        {
            capacity[i] -= rocks[i];
        }

        sort(capacity.begin(), capacity.end());
        int count = 0;

        for (int i = 0; i < capacity.size(); i++)
        {
            if (capacity[i] == 0)
                count++;

            else if (capacity[i] <= n)
            {
                count++;
                n -= capacity[i];
            }
            else
                break;
        }
        return count;
    }
};