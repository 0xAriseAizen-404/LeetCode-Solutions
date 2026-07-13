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
// Morris Traversal
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *prev = nullptr;

        while (root) {
            if (!root->left) {
                if (prev && prev->val > root->val) {
                    if (!first) first = prev;
                    second = root;
                }
                prev = root;
                root = root->right;
            } else {
                TreeNode *prevNode = root->left;
                while (prevNode->right && prevNode->right != root) prevNode = prevNode->right;
                if (!prevNode->right) {
                    prevNode->right = root;
                    root = root->left;
                } else {
                    prevNode->right = nullptr;
                    if (prev && prev->val > root->val) {
                        if (!first) first = prev;
                        second = root;
                    }
                    prev = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};
// TC: O(N)
// SC: O(1)

// Stack + Iterative
// class Solution {
// public:
//     void recoverTree(TreeNode* root) {
//         TreeNode *first = nullptr;
//         TreeNode *second = nullptr;
//         TreeNode *prev = nullptr;
//
//         stack<TreeNode *> st;
//         while (root || !st.empty()) {
//             while (root) {
//                 st.push(root);
//                 root = root->left;
//             }
//             root = st.top(); st.pop();
//             if (prev && prev->val > root->val) {
//                 if (!first) first = prev;
//                 second = root;
//             }
//             prev = root;
//             root = root->right;
//         }
//         int val = first->val;
//         first->val = second->val;
//         second->val = val;
//     }
// };
// TC: O(N)
// SC: O(h)