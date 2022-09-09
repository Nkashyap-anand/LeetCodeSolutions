class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>> &arr)
    {

        sort(arr.begin(), arr.end(), comp);

        int maxNow = INT_MIN, ans = 0;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i][1] < maxNow)
                ans++;
            maxNow = max(maxNow, arr[i][1]);
        }
        return ans;
    }
};