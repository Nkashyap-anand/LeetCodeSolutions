class Solution
{
public:
    vector<int> countDigit(int n)
    {
        vector<int> count(10);
        while (n > 0)
        {
            count[n % 10]++;
            n /= 10;
        }
        return count;
    }
    bool reorderedPowerOf2(int n)
    {

        vector<int> digit = countDigit(n);

        for (int i = 0, pow2 = 1; i < 30; i++, pow2 <<= 1)
        {
            if (digit == countDigit(pow2))
                return true;
        }
        return false;
    }
};