class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> uMap;
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int maxLength = 0;
        for(right=0;right<s.size();right++) {
            uMap[s[right]]++;
            maxFreq = max(maxFreq, uMap[s[right]]);
            if(right-left+1-maxFreq > k) {
                uMap[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};