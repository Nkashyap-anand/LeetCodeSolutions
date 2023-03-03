class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        int i = 0;
        return build(i, preorder, INT_MAX);
    }

    TreeNode *build(int &i, vector<int> &A, int bound)
    {
        if (i == A.size() || A[i] > bound)
            return NULL;
        TreeNode *node = new TreeNode(A[i]);
        i++;
        node->left = build(i, A, node->val);
        node->right = build(i, A, bound);
        return node;
    }
};