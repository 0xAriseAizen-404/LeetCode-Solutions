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
    // Helper function to perform DFS and calculate perfect subtree sizes
    pair<int, bool> dfs(TreeNode* root, vector<int>& sizes) {
        if (!root) return {0, true};  // Empty subtree is perfect with size 0

        auto [leftSize, isLeftPerfect] = dfs(root->left, sizes);
        auto [rightSize, isRightPerfect] = dfs(root->right, sizes);

        // Check if the current subtree is perfect
        if (isLeftPerfect && isRightPerfect && leftSize == rightSize) {
            int currentSize = 1 + leftSize + rightSize;
            sizes.push_back(currentSize);  // Add the size of the perfect subtree
            return {currentSize, true};
        }

        return {0, false};  // If not perfect, return size 0 and false
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;  // Stores sizes of perfect subtrees

        dfs(root, sizes);  // Perform DFS to collect sizes

        // Sort sizes in descending order
        sort(sizes.rbegin(), sizes.rend());

        // Return the k-th largest if it exists, else return -1
        if (k > sizes.size()) return -1;
        return sizes[k - 1];
    }
};