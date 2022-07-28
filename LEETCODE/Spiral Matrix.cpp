class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int startRow = 0;
        int startCol = 0;
        int endRow = row - 1;
        int endCol = col - 1;

        int total = row * col;
        int count = 0;

        while (count < total)
        {
            // starting row
            for (int i = startCol; count < total && i <= endCol; i++)
            {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            // ending col
            for (int i = startRow; count < total && i <= endRow; i++)
            {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            // ending row
            for (int i = endCol; count < total && i >= startCol; i--)
            {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            // start col
            for (int i = endRow; count < total && i >= startRow; i--)
            {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};