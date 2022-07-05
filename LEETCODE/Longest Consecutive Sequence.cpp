class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        set<int> s;

        for (int num : nums)
        {
            s.insert(num);
        }

        int count = 0;

        for (int num : nums)
        {
            if (!s.count(num - 1))
            {
                int currNo = num;
                int currCount = 1;

                while (s.count(currNo + 1))
                {
                    currCount += 1;
                    currNo += 1;
                }
                count = max(count, currCount);
            }
        }
        return count;
    }
};