class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {

        stack<int> s;

        int i = 0;

        for (auto it : pushed)
        {
            s.push(it);

            while (i < pushed.size() && !s.empty() && popped[i] == s.top())
            {
                s.pop();
                i++;
            }
        }

        return s.empty();
    }
};