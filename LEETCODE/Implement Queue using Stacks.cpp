// using two stacks o(2n) space and o(n) time
class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue()
    {
    }

    void push(int x)
    {

        while (!s1.empty())
        {
            int elm = s1.top();
            s2.push(elm);
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty())
        {
            int elm = s2.top();
            s1.push(elm);
            s2.pop();
        }
    }

    int pop()
    {
        int elm = s1.top();
        s1.pop();
        return elm;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

// O(1) amortized
class MyQueue
{
public:
    stack<int> in;
    stack<int> out;
    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {

        int elm;

        if (!out.empty())
        {
            elm = out.top();
            out.pop();
            return elm;
        }

        else
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            elm = out.top();
            out.pop();
        }
        return elm;
    }

    int peek()
    {
        if (!out.empty())
        {
            return out.top();
        }

        else
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
            return out.top();
        }
    }

    bool empty()
    {
        return in.empty() && out.empty();
    }
};