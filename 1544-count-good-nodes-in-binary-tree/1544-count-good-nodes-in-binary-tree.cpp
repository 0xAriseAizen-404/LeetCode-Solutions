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
    int check(TreeNode *node, int maxVal) {
        if (!node) return 0;
        if (node->val < maxVal) return check(node->left, maxVal) + check(node->right, maxVal);
        return 1 + check(node->left, node->val) + check(node->right, node->val);
    }
public:
    int goodNodes(TreeNode* root) {
        return 1 + check(root->left, root->val) + check(root->right, root->val);
    }
};