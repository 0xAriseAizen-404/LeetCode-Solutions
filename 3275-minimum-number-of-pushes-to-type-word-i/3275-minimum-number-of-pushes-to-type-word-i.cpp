class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char ch: word) ++freq[ch - 'a'];
        // sort(freq.rbegin(), freq.rend());
        sort(freq.begin(), freq.end(), greater<int>());
        int cost = 0;
        for (int i = 0; i < 26 && freq[i]; i++) {
            cost += (freq[i] * (i / 8 + 1));
        }
        return cost;
    }
};
// TC: O(n) + O(26log(26)) + O(26) = O(n)
// SC: O(26) = O(1)