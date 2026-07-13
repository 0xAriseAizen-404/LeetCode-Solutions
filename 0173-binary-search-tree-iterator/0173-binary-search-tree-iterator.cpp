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
// Morris Traversal: (Not Safe)
class BSTIterator {
private:
    TreeNode *curr;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        while (curr) {
            if (!curr->left) {
                int res = curr->val;
                curr = curr->right;
                return res;
            } else {
                TreeNode *prev=curr->left;
                while(prev->right && prev->right != curr) prev=prev->right;
                if(prev->right){
                    prev->right=nullptr;
                    int res=curr->val;
                    curr=curr->right;
                    return res;
                } else {
                    prev->right=curr;
                    curr=curr->left;
                }
            }
        }
        return INT_MAX;
    }
    
    bool hasNext() {
        return curr;
    }
};
// TC:
// BSTIterator(): O(H)
// next(): O(1) amortized
// hasNext(): O(1)

// SC:
// O(1)

// Stack
// class BSTIterator {
// private:
//     stack<TreeNode *> st;
//     void pushAllOnLeft(TreeNode *root) {
//         while (root) {
//             st.push(root);
//             root = root->left;
//         }
//     }
// public:
//     BSTIterator(TreeNode* root) {
//         pushAllOnLeft(root);
//     }
    
//     int next() {
//         TreeNode* node = st.top();
//         st.pop();
//         pushAllOnLeft(node->right);
//         return node->val;
//     }
    
//     bool hasNext() {
//         return !st.empty();
//     }
// };
// TC:
// BSTIterator(): O(H)
// next(): O(1) amortized
// hasNext(): O(1)

// SC:
// O(H)

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */