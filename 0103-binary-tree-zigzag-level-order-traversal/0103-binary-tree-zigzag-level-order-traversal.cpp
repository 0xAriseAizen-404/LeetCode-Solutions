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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        stack<TreeNode *> s1; // R2L
        stack<TreeNode *> s2; // L2R
        // s1.push(root); // if lvl-1 is L2R
        s2.push(root); // if lvl-1 is R2L
        while (!s1.empty() || !s2.empty()) {
            vector<int> v;
            while (!s1.empty()) { // R2L
                TreeNode *temp = s1.top(); s1.pop();
                v.push_back(temp->val);
                if (temp->right) s2.push(temp->right);
                if (temp->left) s2.push(temp->left);
            }
            if (!v.empty()) ans.push_back(v);
            v.clear();
            while (!s2.empty()) { // L2R
                TreeNode *temp = s2.top(); s2.pop();
                v.push_back(temp->val);
                if (temp->left) s1.push(temp->left);
                if (temp->right) s1.push(temp->right);
            }
            if (!v.empty()) ans.push_back(v);
        }
        return ans;
    }
};