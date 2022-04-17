// crackhead solution (no way to i can think this)

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root, TreeNode *tail = NULL)
    {

        if (!root)
            return tail;

        TreeNode *ans = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);

        return ans;
    }
};