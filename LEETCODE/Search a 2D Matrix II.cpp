class Solution
{
public:
    bool binarySearch(vector<vector<int>> &matrix, int target, int row)
    {
        int l = 0;
        int r = matrix[0].size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (matrix[row][mid] == target)
                return true;

            else if (matrix[row][mid] < target)
                l = mid + 1;

            else
                r = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            if (binarySearch(matrix, target, i))
                return true;
        }
        return false;
    }
};