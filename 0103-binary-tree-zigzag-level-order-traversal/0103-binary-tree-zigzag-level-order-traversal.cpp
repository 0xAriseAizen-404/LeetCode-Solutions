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
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> que;
        que.push(root);
        bool leftToRight = true;
        while (!que.empty()) {
            int sz = que.size();
            vector<int> levelElements(sz);
            for (int i=0; i<sz; ++i) {
                TreeNode *curr = que.front(); que.pop();
                // fill in zigzag order
                int idx = (leftToRight) ? i : (sz - 1 - i);
                levelElements[idx] = curr->val;
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            res.push_back(levelElements);
            levelElements.clear();
            leftToRight = !leftToRight;
        }
        return res;
    }
};