class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(std::string s, int k) {
        int windowStart = 0;
        int maxCount = 0;
        int count = 0;
        for (int windowEnd = 0; windowEnd < s.size(); ++windowEnd) {
            if (isVowel(tolower(s[windowEnd]))) {
                count++;
            }
            if (windowEnd >= k - 1) {
                maxCount = max(maxCount, count);
                if (isVowel(tolower(s[windowStart]))) {
                    count--;
                }
                windowStart++;
            }
        }
        return maxCount;
    }
};