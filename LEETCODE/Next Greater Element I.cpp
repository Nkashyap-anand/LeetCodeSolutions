class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        stack<int> s;
        map<int, int> m;
        vector<int> ans;
        int n2 = nums2.size();

        for (int i = n2 - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums2[i])
                s.pop();
            if (!s.empty())
                m[nums2[i]] = s.top();
            else
                m[nums2[i]] = -1;

            s.push(nums2[i]);
        }

        for (auto i : nums1)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};