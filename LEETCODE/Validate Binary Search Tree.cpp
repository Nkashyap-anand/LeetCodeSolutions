class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isBst(root, LONG_MIN, LONG_MAX);
    }

    bool isBst(TreeNode *root, long minVal, long maxVal)
    {
        if (root == NULL)
            return true;
        if (root->val >= maxVal || root->val <= minVal)
            return false;
        return isBst(root->left, minVal, root->val) && isBst(root->right, root->val, maxVal);
    }
};