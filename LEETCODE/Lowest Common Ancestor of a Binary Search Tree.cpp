class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};

// another way
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL)
            return NULL;

        int curr = root->val;

        if (p->val < curr && q->val < curr) // they both lie on left
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > curr && q->val > curr) // they both lie on right
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};