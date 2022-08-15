// binary search
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            int lb = 0, ub = nums2.size() - 1, mid = 0;
            while (lb <= ub)
            {
                mid = lb + (ub - lb) / 2;
                if (nums2[mid] == nums1[i])
                {
                    if (find(ans.begin(), ans.end(), nums2[mid]) != ans.end())
                        break;
                    ans.push_back(nums2[mid]);
                    break;
                }
                else if (nums2[mid] < nums1[i])
                    lb = mid + 1;
                else
                    ub = mid - 1;
            }
        }
        return ans;
    }
};

// using map
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> freq;
        vector<int> v;

        for (int i = 0; i < nums1.size(); i++)
        {
            freq[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (freq[nums2[i]] > 0)
            {
                freq[nums2[i]] = 0;
                v.push_back(nums2[i]);
            }
        }

        return v;
    }
};