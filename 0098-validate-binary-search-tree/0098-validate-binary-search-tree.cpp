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
public:
    bool isValidBST(TreeNode* root) {
        // long long prev_val = (long long) INT_MIN - 1;
        long long prev_val = LLONG_MIN;
        TreeNode *node = root;
        bool valid = true;
        while (node) {
            if (!node->left) {
                if (prev_val >= node->val) valid = false;
                prev_val = node->val;
                node = node->right;
            } else {
                TreeNode *prev = node->left;
                while (prev->right && prev->right!=node) prev = prev->right;
                if (!prev->right) {
                    prev->right = node;
                    node = node->left;
                } else {
                    prev->right = nullptr;
                    if (prev_val >= node->val) valid = false;
                    prev_val = node->val;
                    node = node->right;
                }
            }
        }
        return valid;
    }
};