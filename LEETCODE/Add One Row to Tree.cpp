class Solution
{
public:
    TreeNode *preorder(TreeNode *root, int val, int depth)
    {
        if (!root)
            return NULL;
        if (depth == 2)
        {
            TreeNode *leftNode = new TreeNode(val);
            TreeNode *rightNode = new TreeNode(val);

            leftNode->left = root->left;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;

            return root;
        }
        preorder(root->left, val, depth - 1);
        preorder(root->right, val, depth - 1);

        return root;
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        return preorder(root, val, depth);
    }
};