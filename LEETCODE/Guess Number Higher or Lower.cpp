class Solution
{
public:
    int guessNumber(int n)
    {

        int l = 1;
        int h = n;

        while (true)
        {
            int mid = l + (h - l) / 2;
            int a = guess(mid);
            if (a == 0)
                return mid;
            else if (a == 1)
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
};