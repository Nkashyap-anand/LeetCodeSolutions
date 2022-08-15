class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // make sure first array is of smaller length i.e n1 < n2
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0;
        int high = n1;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            // works for both odd and even lengths
            int mid2 = (n1 + n2 + 1) / 2 - mid1;
            // we create two search spaces for applying binary search. left half and right half have elements
            // from both the arrays. left1 & right1 have elements from nums1 and  left2 & right2 have elements from nums2
            // left half should be smaller than right half
            // l1 is max of left1 list, l2 is max of left2 list
            // r1 is min of right1 list, r2 is min of right2 list
            int l1 = (mid1 - 1 < 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 - 1 < 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            // correct partioning
            if (l1 <= r2 && l2 <= r1)
            {
                // even length -> two medians -> return average of both
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                // odd length -> one median -> return it
                else
                    return max(l1, l2);
            }
            if (l1 > r2)
            {
                high = mid1 - 1;
            }
            if (l2 > r1)
            {
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};