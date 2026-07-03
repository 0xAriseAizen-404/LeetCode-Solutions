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
                    // left root right
                    // if there is no left subtree then just push root value, move to right
                    inorder.push_back(node->val);
                    node = node->right;
                } else {
                    TreeNode *prev = node->left;
                    // Finding the RightMost node, to make a connection to Root. have to check if already we made a connection or not.
                    while (prev->right && prev->right != node) prev = prev->right;
                    // if there is no connect, then make the connection to node, now that we made the connection, we are already standing at Node right. so then move to left substree, because this is inorder rigth - left root right, now we made a connection, traverse to left substree, then we will get back to the rightmost node and then now already there is a connection right we will just push the node and mode to right in else part.
                    // understand right ?
                    // get to the RightMost node, if there is not connection make the connection to root, and go the left
                    // traverse all the left and then we will get to rightmost node and then already there is a connection right, so we remove that connection and push the node value, move to right substree of node.
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