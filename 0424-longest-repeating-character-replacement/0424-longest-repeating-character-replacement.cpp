class Solution {
public:
    int characterReplacement(string s, int k) {
        int *chars = new int[26]();
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int maxLen = 0;
        while (right < s.length()) {
            maxFreq = max(maxFreq, ++chars[s[right] - 'A']);
            if ((right-left+1) - maxFreq > k) --chars[s[left++] - 'A'];
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};