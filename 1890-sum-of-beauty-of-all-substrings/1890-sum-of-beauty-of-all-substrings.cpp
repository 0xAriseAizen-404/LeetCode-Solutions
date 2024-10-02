class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0, minFreq = INT_MAX;
            for (int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                maxFreq = max(maxFreq, freq[s[j] - 'a']);
                minFreq = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};
