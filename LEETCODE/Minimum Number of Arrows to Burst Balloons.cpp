bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        if (points.size() == 0)
            return 0;

        sort(points.begin(), points.end(), comp);
        int ans = 1, last = points[0][1];

        for (int i = 0; i < points.size(); i++)
        {
            if (points[i][0] > last)
            {
                ans++;
                last = points[i][1];
            }
        }
        return ans;
    }
};