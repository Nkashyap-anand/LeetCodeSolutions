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

// simlified sol
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix.size() == 0)
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        int rowId = 0, colId = col - 1;

        while (rowId < row && colId >= 0)
        {
            int elm = matrix[rowId][colId];

            if (elm == target)
                return 1;
            if (elm < target)
                rowId++;
            else
                colId--;
        }
        return 0;
    }
};