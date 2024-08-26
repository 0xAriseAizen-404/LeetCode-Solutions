/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> myHelper(Node *root, vector<int> &res) {
        if (root == nullptr) return res;
        if ((root->children).empty()) {
            res.push_back(root->val);
            return res;
        }
        for (int i=0; i<(root->children).size(); ++i) {
            myHelper(root->children[i], res);
        }
        res.push_back(root->val);
        return res;
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        return myHelper(root, res);
    }
};