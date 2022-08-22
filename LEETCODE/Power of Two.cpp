// using bitwise operator
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n > 0 && ((n & (n - 1)) == 0))
            return true;
        return false;
    }
};

// iterative solution
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return 0;
        while (n % 2 == 0)
            n /= 2;
        return n == 1;
    }
};