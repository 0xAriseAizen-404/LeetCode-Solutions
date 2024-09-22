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
    int myHelper(TreeNode* node) {
        if (!node) return 0;
        return 1 + myHelper(node->left) + myHelper(node->right);
    }
public:
    int countNodes(TreeNode* root) {
        return myHelper(root);
    }
};