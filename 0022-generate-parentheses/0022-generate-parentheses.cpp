class Solution {
public:
    // this is my own thought process
    void helper(vector<string> &ans, string str, int opens, int closes) {
        if (opens == 0 && closes == 0) {
            ans.push_back(str);
            return;
        }
        if (opens > 0)
            helper(ans, str+"(", opens - 1, closes);
        if (opens < closes)
            helper(ans, str+")", opens, closes - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n, n);
        return ans;
    }
};