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

// Iterative Approach
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *dummy = root;
        while (dummy) {
            if (val <= dummy->val) {
                if (!dummy->left) {
                    dummy->left = new TreeNode(val); break;
                } else dummy = dummy->left;
            } else {
                if (!dummy->right) {
                    dummy->right = new TreeNode(val); break;
                } else dummy = dummy->right;
            }
        }
        return root;
    }
};
// TC: O(H)  -> Average: O(log N), Worst: O(N)
// SC: O(1)

// Recursive Approach
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if (!root) return new TreeNode(val);
//         if (val <= root->val) root->left = insertIntoBST(root->left, val);
//         if (root->val < val) root->right = insertIntoBST(root->right, val);
//         return root;
//     }
// };
// TC: O(H)  -> Average: O(log N), Worst: O(N)
// SC: O(H)  -> Average: O(log N), Worst: O(N)