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
    TreeNode *findMin(TreeNode *node) {
        while (node->left) node = node->left;
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else {
            // Node found
            // Case 1: no left child
            if (!root->left) {
                TreeNode *nextNode = root->right;
                delete root;
                return nextNode;
            }
            // Case 2: no right child
            if (!root->right) {
                TreeNode *nextNode = root->left;
                delete root;
                return nextNode;
            }
            // Case 3: two children
            TreeNode *successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};