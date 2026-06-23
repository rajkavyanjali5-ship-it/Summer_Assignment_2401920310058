class Solution {
public:

    vector<vector<int>> result;

    void dfs(TreeNode* root,
             int targetSum,
             vector<int>& path) {

        if(root == NULL)
            return;

        path.push_back(root->val);

        if(root->left == NULL &&
           root->right == NULL &&
           targetSum == root->val) {

            result.push_back(path);
        }

        dfs(root->left,
            targetSum - root->val,
            path);

        dfs(root->right,
            targetSum - root->val,
            path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root,
                                int targetSum) {

        vector<int> path;

        dfs(root, targetSum, path);

        return result;
    }
};
