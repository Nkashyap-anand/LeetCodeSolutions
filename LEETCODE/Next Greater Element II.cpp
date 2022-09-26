class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // circular integer array -> when we consider first element as the next of the last element hence it's circular
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; i--) // 2*nums.size()-1 beacuse we assuming a joint imaginary array same as nums
        {
            while (!s.empty() && s.top() <= nums[i % n])
                s.pop();
            // check  if the stack is not empty  and the check the top element of the stack if there is an element present which is smaller than i% nums.size

            if (i < n)
            {
                if (!s.empty())
                    ans[i] = s.top();
            }
            s.push(nums[i % n]);
        }
        return ans;
    }
};