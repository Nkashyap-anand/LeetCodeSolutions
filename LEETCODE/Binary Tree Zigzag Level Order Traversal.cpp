class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        bool leftToright = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *newNode = q.front();
                q.pop();

                // go left to right then go to right to left
                int index = (leftToright) ? i : size - 1 - i;

                level[index] = newNode->val;

                if (newNode->left)
                    q.push(newNode->left);
                if (newNode->right)
                    q.push(newNode->right);
            }
            // change sides on next level
            leftToright = !leftToright;
            result.push_back(level);
        }
        return result;
    }
};