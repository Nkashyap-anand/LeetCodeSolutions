// Sort the array A.
// Keep removing the smallest element n and 2 * n from the array, and put n into the answer until A becomes empty.
// Anytime we can't do the removal, we return empty array.

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &A)
    {
        if (A.size() % 2)
            return {};
        multiset<int> s(begin(A), end(A));
        vector<int> ans;
        for (int i = 0; i < A.size(); i += 2)
        {
            int n = *s.begin();
            ans.push_back(n);
            s.erase(s.begin());
            if (s.find(2 * n) == s.end())
                return {};
            s.erase(s.find(2 * n));
        }
        return ans;
    }
};