// easy aproach

class Solution
{
public:
    vector<int> v;

    void inorder(TreeNode *node)
    {
        if (node == NULL)
            return;
        /* first recur on left child */
        inorder(node->left);

        v.push_back(node->val);

        /* now recur on right child */
        inorder(node->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {

        inorder(root);

        return v[k - 1];
    }
};

// without extra space
class Solution
{
public:
    int ans = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return ans;
    }

    void inorder(TreeNode *root, int &k)
    {
        if (!root)
            return;

        inorder(root->left, k);
        if (--k == 0)
        {
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }
};