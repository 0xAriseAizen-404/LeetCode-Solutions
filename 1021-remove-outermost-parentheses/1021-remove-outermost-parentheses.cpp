class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opens = 0;
        for (const char& ch: s) {
            if (ch == '(') {
                opens += 1;
                if (opens > 1) result += ch;
            } else {
                if (opens > 1) result += ch;
                opens -= 1;
            }
        }
        return result;
    }
};