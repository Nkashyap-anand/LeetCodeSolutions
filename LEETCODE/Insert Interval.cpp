class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // skip to where we need to merge
        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        // now to merge
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // now process the left out element of intervals

        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};