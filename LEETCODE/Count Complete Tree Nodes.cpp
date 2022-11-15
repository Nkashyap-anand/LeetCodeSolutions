// using  recurrsion
class Solution
{
    int cnt = 0;

public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        ++cnt;
        countNodes(root->left);
        countNodes(root->right);
        return cnt;
    }
};

// using bfs (more space complexity)
class Solution
{
public:
    int countNodes(TreeNode *root)
    {

        int count = 0;
        if (root == NULL)
            return count;

        queue<TreeNode *> q;
        q.push(root);
        count++;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    q.push(node->left);
                    count++;
                }

                if (node->right)
                {
                    q.push(node->right);
                    count++;
                }
            }
        }
        return count;
    }
};
