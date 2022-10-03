class Solution
{
public:
    int minCost(string colors, vector<int> &cost)
    {
        // keep track of previous cost and character
        int prevCost = 0, ans = 0;
        char prevChar = '*';

        for (int i = 0; i < colors.size(); i++)
        {
            // if two same color occurs(invalid case)
            if (colors[i] == prevChar)
            {
                // we pick smaller cost and update previous cost accordingly
                if (cost[i] > prevCost)
                {
                    ans += prevCost;
                    prevCost = cost[i];
                }
                else
                {
                    ans += cost[i];
                }
            }
            // different color(valid case)
            else
            {
                prevCost = cost[i];
                prevChar = colors[i];
            }
        }
        return ans;
    }
};