class Solution
{
public:
    vector<vector<int>> ans;

    void solve(TreeNode *root, vector<int> &path, int targetSum, int currSum)
    {
        if (!root)
            return;

        currSum += root->val;
        path.push_back(root->val);

        if (currSum == targetSum && !root->left && !root->right)
            ans.push_back(path);

        solve(root->left, path, targetSum, currSum);
        solve(root->right, path, targetSum, currSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<int> path;
        solve(root, path, targetSum, 0);

        return ans;
    }
};