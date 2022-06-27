class Solution
{
public:
    int minPartitions(string n)
    {
        int max_elm = 0;

        for (auto c : n)
        {
            max_elm = max(max_elm, c - '0');
        }

        return max_elm;
    }
};