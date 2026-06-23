class Codec {
public:

    void serializeTree(TreeNode* root, string& data) {

        if(root == NULL) {
            data += "#,";
            return;
        }

        data += to_string(root->val) + ",";

        serializeTree(root->left, data);
        serializeTree(root->right, data);
    }

    string serialize(TreeNode* root) {

        string data;
        serializeTree(root, data);

        return data;
    }

    TreeNode* deserializeTree(stringstream& ss) {

        string value;
        getline(ss, value, ',');

        if(value == "#")
            return NULL;

        TreeNode* node = new TreeNode(stoi(value));

        node->left = deserializeTree(ss);
        node->right = deserializeTree(ss);

        return node;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);
        return deserializeTree(ss);
    }
};
