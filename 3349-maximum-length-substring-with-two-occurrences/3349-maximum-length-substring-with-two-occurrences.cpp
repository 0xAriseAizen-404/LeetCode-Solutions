class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> hash(26, 0);
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            int idx = s[right] - 'a';
            if (hash[idx] == 2) {
                while (s[left] != s[right]) hash[s[left++] - 'a']--;
                hash[s[left] - 'a']--; left++;
            }
            hash[idx]++;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};