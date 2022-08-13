class Solution
{
public:
    bool isValid(vector<int> &arr, int target, int d)
    {
        int l = 0, h = arr.size() - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (abs(arr[mid] - target) <= d)
                return false;

            else if (arr[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return true;
    }

    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {

        sort(arr2.begin(), arr2.end());
        int count = 0;

        for (auto num : arr1)
        {
            if (isValid(arr2, num, d))
                count++;
        }
        return count;
    }
};