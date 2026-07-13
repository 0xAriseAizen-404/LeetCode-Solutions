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
// Approach 1: Recursive Inorder + Two Pointers
class Solution {
private:
    void storeInOrder(TreeNode* root, vector<int>& inOrder) {
        if(root == nullptr) {
            return;
        }
        storeInOrder(root->left, inOrder);
        inOrder.push_back(root->val);
        storeInOrder(root->right, inOrder);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        storeInOrder(root, inOrder);
        
        int left = 0;
        int right = inOrder.size() - 1;
        while (left < right) {
            int summ = inOrder[left] + inOrder[right];
            if (summ == k) return true;
            else if (summ < k) left++;
            else right--;
        }
        return false;
    }
};
// TC: O(N)
// SC: O(N)

// Approach 2: Stack Iterative Traversal + Hash Set
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         set<int> sset;
//         stack<TreeNode*> st;
//         while (root || !st.empty()) {
//             while (root) {
//                 st.push(root);
//                 root = root->left;
//             }
//             root = st.top(); st.pop();
//             if (sset.count(k - root->val)) return true;
//             sset.insert(root->val);
//             root = root->right;
//         }
//         return false;
//     }
// };
// TC: O(N)
// SC: O(N + h) = O(N)

// Approach 3: Morris Traversal + Hash Set
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         bool found = false;
//         set<int> sset;
//         while (root) {
//             if (!root->left) {
//                 if (sset.count(k - root->val)) found = true;
//                 sset.insert(root->val);
//                 root = root->right;
//             } else {
//                 TreeNode* prev = root->left;
//                 while (prev->right && prev->right != root) prev = prev->right;
//                 if (!prev->right) {
//                     prev->right = root;
//                     root = root->left;
//                 } else {
//                     prev->right = nullptr;
//                     if (sset.count(k - root->val)) found = true;
//                     sset.insert(root->val);
//                     root = root->right;
//                 }
//             }
//         }
//         return found;
//     }
// };
// TC: O(N)
// SC: O(N)   // HashSet dominates, Morris traversal itself is O(1)