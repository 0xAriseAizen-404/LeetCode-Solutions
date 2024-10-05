class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        bool dp[length][length];
        memset(dp, 0, sizeof(dp));
        int max_pal_length = 1;
        for (int i = 0; i < length; i++){
            dp[i][i] = true;
        }
        int start = 0;
        for (int j = 0; j < length - 1; j++){
            if (s[j] == s[j + 1]){
                dp[j][j + 1] = true;
                start = j;
                max_pal_length = 2;
            }
        }
        for (int k = 3; k <= length; ++k) {
            for (int i = 0; i < length - k + 1; ++i) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > max_pal_length) {
                        start = i;
                        max_pal_length = k;
                    }
                }
            }
        }
        return s.substr(start, max_pal_length);
    }
};