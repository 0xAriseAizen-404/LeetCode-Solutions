class Solution {
public:
    bool checkString(string s) {
        char x = 'a';
        for (int ind = 0; ind < s.length(); ++ind) {
            if (s[ind] == x) continue;
            else {
                if (ind == 0 || x == 'a') x = s[ind];
                else return false;
            }
        }
        return true;
    }
};