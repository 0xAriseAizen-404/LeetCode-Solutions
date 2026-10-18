class Solution {
public:
    int minInsertions(string s) {
        int opens = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') opens++;
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') i++;
                else ans++; // insert one '('

                if (opens > 0) opens--;
                else ans++; // insert one '('
            }
        }
        return ans + 2 * opens;
    }
};