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

// Morris Inorder Traversal
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> inorder;
            TreeNode *node = root;
            while (node != nullptr) {
                if (node->left == nullptr) {
                    inorder.push_back(node->val);
                    node = node->right;
                } else {
                    TreeNode *prev = node->left;
                    while (prev->right && prev->right != node) prev = prev->right;
                    if (prev->right == nullptr) {
                        prev->right = node;
                        node = node->left;
                    } else {
                        prev->right = nullptr;
                        inorder.push_back(node->val);
                        node = node->right;
                    }
                }
            }
            return inorder;
        }
};

// Recursive Approach
// class Solution {
// private:
//     void inOrder(TreeNode *root, vector<int> &res) {
//         if (!root) return;
//         inOrder(root->left, res);
//         res.push_back(root->val);
//         inOrder(root->right, res);
//     }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inOrder(root, res);
//         return res;
//     }
// };
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed

// Iterative Approach
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         stack<TreeNode *> st;
//         TreeNode *curr = root;
//         while (curr || !st.empty()) {
//             while (curr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }
//             curr = st.top(); st.pop();
//             res.push_back(curr->val);
//             curr = curr->right;
//         }
//         return res;
//     }
// };
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed