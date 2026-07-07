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

// Stack + Iterative Approach
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top(); st.pop();
            if (--k == 0) return node->val;
            node = node->right;
        }
        return -1;
    }
};
// TC: O(h + k) avg // O(n) worst
// SC: O(h)


// Morris Inorder Traversal
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         int ans = 0;
//         int cnt = 0;
//         TreeNode* node = root;
//         while (node) {
//             if (!node->left) {
//                 if (++cnt == k) ans = node->val;
//                 node = node->right;
//             } else {
//                 TreeNode* prev = node->left;
//                 while (prev->right && prev->right != node) prev = prev->right;
//                 if (!prev->right) {
//                     prev->right = node;
//                     node = node->left;
//                 } else {
//                     prev->right = nullptr;
//                     if (++cnt == k) ans = node->val;
//                     node = node->right;
//                 }
//             }
//         }
//         return ans;
//     }
// };
// TC: O(n)
// SC: O(1)

// Morris Inorder Traversal
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         TreeNode *node = root;
//         while (node) {
//             if (!node->left) {
//                 ans.push_back(node->val);
//                 node = node->right;
//             } else {
//                 TreeNode *prev = node->left;
//                 while (prev->right && prev->right!=node) prev = prev->right;
//                 if (!prev->right) {
//                     prev->right = node;
//                     node = node->left;
//                 } else {
//                     prev->right = nullptr;
//                     ans.push_back(node->val);
//                     node = node->right;
//                 }
//             }
//         }
//         return ans[k-1];
//     }
// };
// TC: O(n)
// SC: O(n) storing ans otherwise O(1)

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         stack<TreeNode *> st;
//         TreeNode *node = root;
//         while (node || !st.empty()) {
//             while (node) {
//                 st.push(node);
//                 node = node->left;
//             }
//             node = st.top(); st.pop();
//             ans.push_back(node->val);
//             node = node->right;
//         }
//         return ans[k-1];
//     }
// };
// TC: O(n)
// SC: O(n) storing ans