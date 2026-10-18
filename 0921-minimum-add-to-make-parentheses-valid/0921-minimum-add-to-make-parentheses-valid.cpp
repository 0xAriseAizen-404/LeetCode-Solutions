class Solution {
public:
    int minAddToMakeValid(string s) {
        int opens = 0;
        int closes = 0;
        for (const char& ch: s) {
            if (ch == '(') opens++;
            else if (ch == ')' && opens > 0) opens--;
            else closes++;
        }
        return (opens + closes);
    }
};