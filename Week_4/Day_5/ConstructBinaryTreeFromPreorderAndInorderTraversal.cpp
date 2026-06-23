class Solution {
public:

    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& preorder,
                    int preStart,
                    int preEnd,
                    vector<int>& inorder,
                    int inStart,
                    int inEnd) {

        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = pos[rootValue];
        int leftSize = rootIndex - inStart;

        root->left = build(preorder,
                           preStart + 1,
                           preStart + leftSize,
                           inorder,
                           inStart,
                           rootIndex - 1);

        root->right = build(preorder,
                            preStart + leftSize + 1,
                            preEnd,
                            inorder,
                            rootIndex + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        for(int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return build(preorder,
                     0,
                     preorder.size() - 1,
                     inorder,
                     0,
                     inorder.size() - 1);
    }
};
