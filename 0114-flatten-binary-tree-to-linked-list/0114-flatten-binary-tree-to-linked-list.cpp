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
// My Own Fucking Solution
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st; st.push(root);
        TreeNode* prev = nullptr;
        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            if (prev) {
                prev->left = nullptr;
                prev->right = node;
            }
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            prev = node;
        }
        if (prev) {
            prev->left = nullptr;
            prev->right = nullptr;
        }
    }
};
// TC: O(n)
//SC: O(h)