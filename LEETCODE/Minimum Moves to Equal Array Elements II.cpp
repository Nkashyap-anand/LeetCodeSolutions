class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int moves = 0;
        int mid = nums[n / 2];

        for (int i = 0; i < n; i++)
        {
            moves += abs(nums[i] - mid);
        }
        return moves;
    }
};