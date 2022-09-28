class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            // remove out of bounds from window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // remove smaller elements from back to keep max at front
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1) // window complete
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};