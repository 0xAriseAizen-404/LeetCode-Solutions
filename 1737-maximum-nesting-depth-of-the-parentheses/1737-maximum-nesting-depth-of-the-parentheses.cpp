class Solution {
public:
    int maxDepth(string s) {
        int opens = 0;
        int mx_depth = 0;
        for (char &x: s) {
            if (x == '(') opens++;
            else if (x == ')') opens--;
            mx_depth = max(mx_depth, opens);
        }
        return mx_depth;
    }
};