// 1st approach space complexity is o(2n)
class MinStack
{
public:
    stack<pair<int, int>> st;

    MinStack()
    {
    }

    void push(int val)
    {

        int mini;
        if (st.empty())
            mini = val;
        else
            mini = min(st.top().second, val);

        st.push({val, mini});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// 2nd approach space complexity is o(n)
class MinStack
{
public:
    stack<long long> st;
    long long mini;

    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {

        if (st.empty())
        {
            st.push(val);
            mini = val;
        }

        else
        {
            if (val < mini)
            {
                long long x = val;
                st.push(2 * x - mini);
                mini = val;
            }
            else
                st.push(val);
        }
    }

    void pop()
    {

        if (st.empty())
            return;

        long long s_top = st.top();
        st.pop();

        if (s_top < mini)
        {
            mini = 2 * mini - s_top;
        }
    }

    int top()
    {

        if (st.empty())
            return -1;
        long long s_top = st.top();

        if (s_top < mini)
            return mini;
        return s_top;
    }

    int getMin()
    {
        return mini;
    }
};