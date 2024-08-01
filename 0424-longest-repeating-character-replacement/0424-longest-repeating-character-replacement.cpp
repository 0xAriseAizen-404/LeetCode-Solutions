class Solution {
public:
    int characterReplacement(string s, int k) {
        int *chars = new int[26]();
        
        int left = 0, right = 0;
        int maxLength = 0;
        int maxxFreq = 0;

        while (right < s.size()) {
            maxxFreq = max(maxxFreq, ++chars[s[right] - 'A']);
            if ((right-left+1) - maxxFreq > k) {
                chars[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
};