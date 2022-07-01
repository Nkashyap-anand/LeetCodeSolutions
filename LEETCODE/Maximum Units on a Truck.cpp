class Solution
{
public:
    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        return v1[1] > v2[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {

        sort(boxTypes.begin(), boxTypes.end(), comp);
        int totalUnits = 0, i = 0;

        while (truckSize > 0 && i < boxTypes.size())
        {
            if (boxTypes[i][0] <= truckSize)
            {
                totalUnits += boxTypes[i][1] * boxTypes[i][0];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                int canTake = truckSize;
                truckSize -= canTake;
                totalUnits += canTake * boxTypes[i][1];
            }
            i++;
        }
        return totalUnits;
    }
};