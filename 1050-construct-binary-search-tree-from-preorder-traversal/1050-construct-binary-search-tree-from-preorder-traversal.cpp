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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        function<TreeNode* (int)> buildBST = [&](int limit) -> TreeNode* {
            if (ind >= preorder.size() || preorder[ind] > limit) return nullptr;
            TreeNode *root = new TreeNode(preorder[ind++]);
            root->left = buildBST(root->val);
            root->right = buildBST(limit);
            return root;
        };
        return buildBST(INT_MAX);
    }
};

// Optimal (LIMIT Method)
// class Solution {
// private:
//     // limit is nothing but - if I am inserting here, then next element in InOrder is my limit, Am I greater than that limit then return NULL else create "ME here".
//     TreeNode* buildBST(vector<int> &preOrder, int &ind, int limit) {
//         if (ind >= preOrder.size() || preOrder[ind] > limit) return nullptr;
//         TreeNode* root = new TreeNode(preOrder[ind++]);
//         root->left = buildBST(preOrder, ind, root->val);
//         root->right = buildBST(preOrder, ind, limit);
//         return root;
//     }
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int ind = 0;
//         return buildBST(preorder, ind, INT_MAX);
//     }
// };
// TC: O(N)
// SC: O(H)   // O(logN) avg, O(N) worst

// Recursive Insertion Method
// class Solution {
// private:
//     void insertIntoBST(TreeNode *root, int x) {
//         if (x < root->val) {
//             if (!root->left) {
//                 root->left = new TreeNode(x);
//                 return;
//             }
//             insertIntoBST(root->left, x);
//         } else {
//             if (!root->right) {
//                 root->right = new TreeNode(x);
//                 return;
//             }
//             insertIntoBST(root->right, x);
//         }
//     }
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         TreeNode *root = nullptr;
//         for (auto &x: preorder) {
//             if (!root) root = new TreeNode(x);
//             else insertIntoBST(root, x);
//         }
//         return root;
//     }
// };
// TC: O(NlogN) avg, O(N^2) worst
// SC: O(H)   // O(logN) avg, O(N) worst