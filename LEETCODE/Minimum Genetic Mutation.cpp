class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {

        queue<string> q;
        unordered_set<string> visited;
        int count = 0;

        q.push(start);
        visited.insert(start);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string node = q.front();
                q.pop();

                if (node == end)
                    return count;

                for (char ch : "ACGT")
                {
                    for (int j = 0; j < node.size(); j++)
                    {
                        string newNode = node;
                        newNode[j] = ch;

                        if (!visited.count(newNode) && find(bank.begin(), bank.end(), newNode) != bank.end())
                        {
                            q.push(newNode);
                            visited.insert(newNode);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};