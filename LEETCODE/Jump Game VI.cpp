class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        // to process elm
        deque<int> q;
        int n = nums.size();
        // to store max score
        vector<int> dp(n);

        // start from pushing last value
        dp[n - 1] = nums[n - 1];
        q.push_back(n - 1);

        // iterate over queue
        for (int i = n - 2; i >= 0; i--)
        {
            // if we go beyond the key then pop them out
            if (q.front() - i > k)
                q.pop_front();

            // calculate sum
            dp[i] = nums[i] + dp[q.front()];

            // if queue is not empty and new sum is greater then pop the queue
            while (q.size() && dp[q.back()] < dp[i])
                q.pop_back();
            // push index
            q.push_back(i);
        }

        // max score is at dp[0]
        return dp[0];
    }
};