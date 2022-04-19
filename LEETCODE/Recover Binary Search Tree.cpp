class Solution
{
private:
    TreeNode *first;
    TreeNode *last;
    TreeNode *mid;
    TreeNode *prev;

    void inorder(TreeNode *node)
    {
        if (!node)
            return;

        inorder(node->left);

        if (prev != NULL && (node->val < prev->val))
        {
            if (first == NULL)
            {
                first = prev;
                mid = node;
            }
            else
                last = node;
        }
        prev = node;

        inorder(node->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = mid = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && mid)
            swap(first->val, mid->val);
    }
};