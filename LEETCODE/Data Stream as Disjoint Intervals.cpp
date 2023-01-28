class SummaryRanges
{
public:
    set<int> values;
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        values.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        if (values.empty())
            return {};

        vector<vector<int>> interval;

        int left = -1, right = -1;
        for (auto value : values)
        {
            if (left < 0)
            {
                left = right = value;
            }

            else if (value == right + 1)
            {
                right = value;
            }

            else
            {
                interval.push_back({left, right});
                left = right = value;
            }
        }
        interval.push_back({left, right});
        return interval;
    }
};
