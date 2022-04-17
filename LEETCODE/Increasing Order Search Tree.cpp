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

// easy to understand recursive approach

class Solution
{
public:
    TreeNode *newroot, *curr;

    TreeNode *increasingBST(TreeNode *root)
    {

        if (!root)
            return NULL;

        increasingBST(root->left);

        if (newroot == NULL)
        {
            newroot = new TreeNode(root->val);
            curr = newroot;
        }
        else
        {
            curr->right = new TreeNode(root->val);
            curr = curr->right;
        }

        increasingBST(root->right);

        return newroot;
    }
};