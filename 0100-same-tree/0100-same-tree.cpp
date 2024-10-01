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
private:
    using Pair = pair<TreeNode*, TreeNode*>;
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<Pair> que;
        que.push({p, q});
        while (!que.empty()) {
            auto [n1, n2] = que.front(); que.pop();
            if (!n1 && !n2) continue;
            if ((n1 && !n2) || (!n1 && n2)) return false;
            if (n1->val != n2->val) return false;
            que.push({n1->left, n2->left});
            que.push({n1->right, n2->right});
        }
        return true;
    }
};
