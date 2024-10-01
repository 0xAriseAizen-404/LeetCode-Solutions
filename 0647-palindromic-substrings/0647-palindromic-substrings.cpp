class Solution {
public:
    int checkPalindrome(string s, int left, int right) {
        int count = 0;
        while (left>=0 && right<=s.size() && s[left]==s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int count = 0;
        for (int i=0; i<s.size(); ++i) {
            count += checkPalindrome(s, i, i);
            count += checkPalindrome(s, i, i+1);
        }
        return count;
    }
};