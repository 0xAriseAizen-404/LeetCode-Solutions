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
    int getSumAtNode(TreeNode *node, int &maxSum) {
        if (!node) return 0;
        int leftSum = max(0, getSumAtNode(node->left, maxSum));
        int rightSum = max(0, getSumAtNode(node->right, maxSum));
        maxSum = max(maxSum, node->val + leftSum + rightSum);
        return node->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        getSumAtNode(root, maxSum);
        return maxSum;
    }
};