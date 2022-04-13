class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> v(n, vector<int> (n));
        
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        int num=1;
        
        while(left<=right && top <= bottom)
        {
            for(int j=left; j<=right; j++)
            {
                v[top][j]= num++;
            }
            top++;
            for(int i=top; i<=bottom; i++)
            {
                v[i][right]=num++;
            }
            right--;
            for(int j=right;j>=left;j--)
            {
                v[bottom][j]=num++;
            }
            bottom--;
            for(int i=bottom; i>=top; i--)
            {
                v[i][left]=num++;
            }
            left++;
        }
        
        return v;
    }
};