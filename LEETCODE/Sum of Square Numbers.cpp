class Solution
{
public:
    bool isSquare(long x)
    {
        if (x == 1 || x == 0)
            return true;

        long s = 0, e = x;

        while (s <= e)
        {
            long mid = s + (e - s) / 2;

            if (mid * mid == x)
                return true;
            else if (mid * mid < x)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }

    bool judgeSquareSum(int c)
    {

        if (c == 1 || c == 0)
            return true;

        for (long i = 0; i * i <= c; i++)
        {
            long x = i * i;
            if (isSquare(c - x))
                return true;
        }
        return false;
    }
};