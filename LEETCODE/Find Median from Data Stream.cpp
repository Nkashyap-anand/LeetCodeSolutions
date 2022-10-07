class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {

        if (maxheap.empty() || maxheap.top() > num)
            maxheap.push(num);
        else
            minheap.push(num);

        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {

        if (minheap.size() == maxheap.size())
            return (maxheap.top() + minheap.top()) / 2.0;
        else
        {
            if (minheap.size() > maxheap.size())
                return minheap.top();
            else
                return maxheap.top();
        }
    }
};
