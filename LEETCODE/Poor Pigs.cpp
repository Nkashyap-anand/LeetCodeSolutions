class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {

        int trial = minutesToTest / minutesToDie;

        return ceil(log(buckets) / log(trial + 1));
    }
};