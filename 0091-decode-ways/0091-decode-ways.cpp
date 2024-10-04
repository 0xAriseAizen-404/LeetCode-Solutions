class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        if (s.size() == 1) return 1;

        int prev2 = 1;
        int prev1 = 1;
        for (int i = 1; i < s.size(); ++i) {
            int curr = 0;
            if (s[i] != '0') {
                curr += prev1;
            }
            int twoDigitNum = stoi(s.substr(i-1, 2));
            if (twoDigitNum >= 10 && twoDigitNum <= 26) {
                curr += prev2;
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
