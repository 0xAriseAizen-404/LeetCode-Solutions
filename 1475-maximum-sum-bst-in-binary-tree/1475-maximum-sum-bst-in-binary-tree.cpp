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
class NodeValue {
public:
    int maxVal, minVal, sum;
    NodeValue(int maxVal, int minVal, int sum) {
        this->maxVal = maxVal;
        this->minVal = minVal;
        this->sum = sum;
    }
};

class Solution {
private:
    NodeValue helper(TreeNode* root, int& ans) {
        if (!root) return NodeValue(INT_MIN, INT_MAX, 0);
        NodeValue left = helper(root->left, ans);
        NodeValue right = helper(root->right, ans);
        if (left.maxVal < root->val && root->val < right.minVal) {
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);
            return NodeValue(max(root->val, right.maxVal),
                                                  min(root->val, left.minVal),
                                                  currSum);
        }

        return NodeValue(INT_MAX, INT_MIN, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};