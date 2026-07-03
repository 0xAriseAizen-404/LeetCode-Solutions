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

// Morris Preorder Traversal
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> preorder;
            TreeNode *node = root;
            while (node != nullptr) {
                if (node->left == nullptr) {
                    // if there is no left subtree then just push root value, no left, move to right
                    preorder.push_back(node->val);
                    node = node->right;
                } else {
                    TreeNode *prev = node->left;
                    // Finding the RightMost node, to make a connection to Root. have to check if already we made a connection or not.
                    while (prev->right && prev->right != node) prev = prev->right;
                    // if there is no connect, then make the connection to node, now that we made the connection, we are already standing at Node right. so push it to the vector. because this is preorder, root left right. so push the root value and then traverse to left. and then after we traverse all the left subtree then we will get beck to here to this node and we will find out we have a connection, so remove that connection in the else part and then move to right.
                    // understand right ?
                    // get to the RightMost node, if there is not connection make the connection to root, and push the root value, go the left
                    // traverse all the left and then we will get to rightmost node and then already there is a connection right, so we remove that connection and move to right substree of node.
                    if (prev->right == nullptr) {
                        prev->right = node;
                        preorder.push_back(node->val);
                        node = node->left;
                    } else {
                        prev->right = nullptr;
                        node = node->right;
                    }
                }
            }
            return preorder;
        }
};

// Recursive Approach
// class Solution {
// private:
//     void preOrder(TreeNode *root, vector<int> &res) {
//         if (!root) return;
//         res.push_back(root->val);
//         preOrder(root->left, res);
//         preOrder(root->right, res);
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         preOrder(root, res);
//         return res;
//     }
// };
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed

// Iterative Approach
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         stack<TreeNode *> st;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode *curr = st.top();
//             res.push_back(curr->val);
//             st.pop();
//             if (curr->right) st.push(curr->right);
//             if (curr->left) st.push(curr->left);
//         }
//         return res;
//     }
// };
// Iterative
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed