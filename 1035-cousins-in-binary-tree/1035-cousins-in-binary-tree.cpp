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
    bool isCousins(TreeNode* root, int a, int b) {
        queue<TreeNode *> que;
        if (!root) return false;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            bool foundA = false;
            bool foundB = false;
            for (int i=0; i<size; ++i) {
                TreeNode *temp = que.front(); que.pop();
                if (temp->val == a) foundA = true;
                if (temp->val == b) foundB = true;
                if (temp->left && temp->right) {
                    if ((temp->left->val == a && temp->right->val == b) ||
                    (temp->left->val == b && temp->right->val == a)) {
                        return false;
                    }
                }
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            if (foundA && foundB) return true;
        }
        return false;
    }
};