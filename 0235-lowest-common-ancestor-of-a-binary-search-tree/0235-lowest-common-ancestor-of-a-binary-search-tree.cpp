/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small_val = min(p->val, q->val);
        int large_val = max(p->val, q->val);
        TreeNode *node = root;
        while (node) {
            if (node->val < small_val) node = node->right;
            else if (large_val < node->val) node = node->left;
            else {
                // node has to be either small or large
                // or A perfect node which has small on its left side and large on its right side, then it is the lowest ancestor.
                return node;
            }
        }
        return nullptr;
    }
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root || root == p || root == q) return root;
//         TreeNode *didYouFindAnyNodeOnLeft = lowestCommonAncestor(root->left, p, q);
//         TreeNode *didYouFindAnyNodeOnRight = lowestCommonAncestor(root->right, p, q);
//         if (didYouFindAnyNodeOnLeft && didYouFindAnyNodeOnRight) return root;
//         return didYouFindAnyNodeOnLeft ? didYouFindAnyNodeOnLeft : didYouFindAnyNodeOnRight;
//     }
// };