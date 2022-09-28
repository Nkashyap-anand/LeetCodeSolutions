// Push every pair of <price, result> to a stack.
// Pop lower price from the stack and accumulate the count.
// One price will be pushed once and popped once.So 2 *N times stack operations and N times calls.

class StockSpanner
{
public:
    stack<pair<int, int>> st;

    StockSpanner()
    {
    }

    int next(int price)
    {

        int res = 1;
        while (!st.empty() && st.top().first <= price)
        {
            res += st.top().second;
            st.pop();
        }
        st.push({price, res});
        return res;
    }
};