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
    int myHelper(TreeNode* node, bool &isValid) {
        if (!node) return 0;
        int lH = myHelper(node->left, isValid);
        int rH = myHelper(node->right, isValid);
        if (abs(lH - rH) > 1) isValid = 0;
        return 1 + max(lH, rH);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isValid = 1;
        myHelper(root, isValid);
        return isValid;
    }
};