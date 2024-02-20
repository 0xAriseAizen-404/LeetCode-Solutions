class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        std::unordered_set<char> charSet;
        while (right < s.length()) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.emplace(s[right]);
                maxLen = std::max(maxLen, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};