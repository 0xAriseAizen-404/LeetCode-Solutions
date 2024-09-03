class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        // int *hash = new int[256];
        // int hash[256];
        // fill_n(hash, 256, -1);
        // int hash[256] = { [0 ... 255] = -1 };
        array<int, 256> hash;
        hash.fill(-1);
        while (right < s.length()) {
            int ind = (int)s[right];
            if (hash[ind] == -1 || hash[ind] < left) {
                hash[ind] = right;
            } else {
                left = hash[ind] + 1;
                hash[ind] = right;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};