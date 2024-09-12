class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int *freq = new int[26]();
        for (char const &c: allowed) freq[tolower(c) - 'a']++;
        int res = 0;
        for (auto const &str: words) {
            int8_t isOk = 1;
            for (char const &c: str) {
                if (freq[tolower(c) - 'a'] == 0) {
                    isOk = 0;
                    break;
                }
            }
            if (isOk == 1) res += 1;
        }
        return res;
    }
};