class Solution {
public:
    void helper(vector<string> &ans, string str, int opens, int closes) {
        if (opens == 0 || closes == 0) {
            for (int i=0; i<closes; ++i) str.push_back(')');
            ans.push_back(str);
            cout<<str<<endl;
            return;
        }
        helper(ans, str+"(", opens-1, closes);
        if (opens < closes)
            helper(ans, str+")", opens, closes - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "(", n-1, n);
        return ans;
    }
};