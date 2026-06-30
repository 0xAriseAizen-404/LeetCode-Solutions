/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void getPaths(TreeNode *node, string &leafPath, vector<string> &paths) {
        if (!node) return;
        int oldLength = leafPath.size();
        leafPath += "->";
        leafPath += to_string(node->val);
        if (node && !node->left && !node->right) paths.push_back(leafPath);
        getPaths(node->left, leafPath, paths);
        getPaths(node->right, leafPath, paths);
        leafPath.resize(oldLength);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string leafPath = to_string(root->val);
        getPaths(root->left, leafPath, paths);
        getPaths(root->right, leafPath, paths);
        if (paths.empty()) paths.push_back(leafPath);
        return paths;
    }
};