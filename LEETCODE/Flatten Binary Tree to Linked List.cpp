// Morris traversal
class Solution
{
public:
    void flatten(TreeNode *root)
    {

        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *prev = curr->left;

                while (prev->right)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// stack
class Solution
{
public:
    void flatten(TreeNode *root)
    {

        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *prev = curr->left;

                while (prev->right)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// recurrsion
class Solution
{
public:
    TreeNode *prev = NULL;

    void flatten(TreeNode *root)
    {

        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};