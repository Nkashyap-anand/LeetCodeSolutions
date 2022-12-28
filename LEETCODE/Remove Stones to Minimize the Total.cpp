class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {

        priority_queue<int> q(piles.begin(), piles.end());

        while (k)
        {
            int temp = q.top();
            q.pop();
            temp = ceil((float)temp / 2.0);
            q.push(temp);
            k--;
        }

        int sum = 0;

        while (!q.empty())
        {
            sum += q.top();
            q.pop();
        }

        return sum;
    }
};