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
