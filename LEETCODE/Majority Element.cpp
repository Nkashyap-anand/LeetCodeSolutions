class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int elm = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                elm = num;
            }
            if (num == elm)
                count++;
            else
                count--;
        }
        return elm;
    }
};