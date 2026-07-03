/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// My Own Fucking Code
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        string data = "[";
        queue<TreeNode *> que; que.push(root);
        int lastValidNode = 0;
        while (!que.empty()) {
            int sz = que.size();
            for (int i=0; i<sz; ++i) {
                TreeNode *node = que.front(); que.pop();
                if (!node) data += "null,";
                else {
                    data += to_string(node->val) + ",";
                    lastValidNode = data.size();
                    que.push(node->left);
                    que.push(node->right);
                }
            }
        }
        data = data.substr(0, lastValidNode);
        data.pop_back();
        data += "]";
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        stringstream ss(data.substr(1, data.size() - 2));
        string item;
        vector<string> parts;
        while (getline(ss, item, ',')) parts.push_back(item);

        // function<TreeNode *(int)> build = [&] (int ind) -> TreeNode *{
        //     if (ind >= parts.size() || parts[ind] == "null") return nullptr;
        //     int rootVal = stoi(parts[ind]);
        //     TreeNode *root = new TreeNode(rootVal);
        //     root->left = build(2 * ind + 1);
        //     root->right = build(2 * ind + 2);
        //     return root;
        // };
        // return build(0);

        TreeNode *root = new TreeNode(stoi(parts[0]));
        queue<TreeNode *> que; que.push(root);
        int ind = 1;
        while (!que.empty() && ind < parts.size()) {
            TreeNode *node = que.front(); que.pop();
            if (ind < parts.size() && parts[ind] != "null") {
                node->left = new TreeNode(stoi(parts[ind]));
                que.push(node->left);
            }
            ind += 1;
            if (ind < parts.size() && parts[ind] != "null") {
                node->right = new TreeNode(stoi(parts[ind]));
                que.push(node->right);
            }
            ind += 1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));