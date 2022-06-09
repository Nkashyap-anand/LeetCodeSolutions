class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        for(int i=0, j=0; i<m+n, j<n; i++, j++)
        {
            nums1[i+m] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};