class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        vector<vector<int>> ans;
        queue<vector<int>> q;

        q.push({0});

        while (!q.empty())
        {
            vector<int> path = q.front();
            q.pop();

            if (path.back() == graph.size() - 1)
                ans.push_back(path);
            else
            {
                for (int child : graph[path.back()])
                {
                    path.push_back(child);
                    q.push(path);
                    path.pop_back();
                }
            }
        }
        return ans;
    }
};