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
    int totalSum = 0;
    int sumN(TreeNode* root,int x){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            totalSum += (x*10)+root->val;
            return 0;
        }
        sumN(root->left,(x*10)+root->val);
        sumN(root->right,(x*10)+root->val);
        return 0;
        }
    int sumNumbers(TreeNode* root) {
        sumN(root,0);
        return totalSum;
    }
};