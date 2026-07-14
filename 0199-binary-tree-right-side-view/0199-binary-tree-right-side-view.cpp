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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightViewNodes;
        if (!root) return rightViewNodes;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            for (int i=0; i<sz; ++i) {
                TreeNode *curr = que.front(); que.pop();
                if (i == 0) rightViewNodes.push_back(curr->val);
                // Right View
                if (curr->right) que.push(curr->right);
                if (curr->left) que.push(curr->left);
                // // Left View
                // if (curr->left) que.push(curr->left);
                // if (curr->right) que.push(curr->right);
            }
        }
        return rightViewNodes;
    }
};

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> rightViewNodes;
//         if (!root) return rightViewNodes;
//         queue<TreeNode *> que;
//         que.push(root);
//         while (!que.empty()) {
//             int sz = que.size();
//             int isFoundAtThisLevel = false;
//             for (int i=0; i<sz; ++i) {
//                 TreeNode *curr = que.front(); que.pop();
//                 if (!isFoundAtThisLevel) {
//                     rightViewNodes.push_back(curr->val);
//                     isFoundAtThisLevel = true;
//                 }
//                 // Right View
//                 if (curr->right) que.push(curr->right);
//                 if (curr->left) que.push(curr->left);
//                 // // Left View
//                 // if (curr->left) que.push(curr->left);
//                 // if (curr->right) que.push(curr->right);
//             }
//         }
//         return rightViewNodes;
//     }
// };

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> rightViewNodes;
//         if (!root) return rightViewNodes;
//         queue<TreeNode *> que;
//         que.push(root);
//         while (!que.empty()) {
//             int sz = que.size();
//             bool firstOne = true;
//             for (int i=0; i<sz; ++i) {
//                 TreeNode *curr = que.front(); que.pop();
//                 if (i == sz - 1) rightViewNodes.push_back(curr->val);
//                 if (curr->left) que.push(curr->left);
//                 if (curr->right) que.push(curr->right);
//             }
//         }
//         return rightViewNodes;
//     }
// };