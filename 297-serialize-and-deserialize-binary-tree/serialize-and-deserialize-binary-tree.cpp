class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if (!curNode) {
                s.append("#,");
            } else {
                s.append(to_string(curNode->val) + ",");
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        if (str == "#") return nullptr;   // handle root being null

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (!getline(ss, str, ',')) break;
            if (str == "#") {
                node->left = nullptr;
            } else {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }

            // Right child
            if (!getline(ss, str, ',')) break;
            if (str == "#") {
                node->right = nullptr;
            } else {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }
        return root;
    }
};