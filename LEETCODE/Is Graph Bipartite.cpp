// Runtime: 36 ms, Memory Usage: 13.5 MB
// easy approach using coloring

class Solution
{
public:
    bool dfs(int src, vector<int> &color, vector<vector<int>> &graph, int col)
    {
        color[src] = col;

        for (int child : graph[src])
        {
            if (color[child] == -1)
            {
                if (dfs(child, color, graph, 1 - col) == false)
                    return false;
            }
            else
            {
                if (color[child] == color[src])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, color, graph, 0) == false)
                    return false;
            }
        }
        return true;
    }
};
s