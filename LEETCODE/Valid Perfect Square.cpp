// binary search solution
class Solution
{
public:
    bool isPerfectSquare(int num)
    {

        long l = 0, r = num;

        while (l <= r)
        {
            long mid = l + (r - l) / 2;

            if (mid * mid < num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return (l * l == num);
    }
};

// mathematical solution
class Solution
{
public:
    bool isPerfectSquare(int num)
    {

        int i = 1;
        while (num > 0)
        {

            num -= i;
            i += 2;
            if (num == 0)
                return true;
        }
        return false;
    }
};