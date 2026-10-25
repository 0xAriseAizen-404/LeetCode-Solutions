class Solution {
public:
    int countMagicalPairs(string s) {
        // we will go from 'j' index, then left part will be [i, j] and right part will be [j+1, n-1]
        // we get distinct values from each side, then multiply them
        int N = s.length();
        int count = 0;
        for (int j = 0; j < N - 1; ++j) {
            // left part
            vector<int> dis1(27, 0);
            vector<bool> appeared(26, false);
            int distinct = 0;
            for (int i = j; i >= 0; --i) {
                if (!appeared[s[i] - 'a']) distinct++;
                appeared[s[i] - 'a'] = true;
                dis1[distinct]++;
            }
            // right part
            vector<int> dis2(27, 0);
            appeared.clear();
            appeared.assign(26, false);
            distinct = 0;
            for (int k = j + 1; k < s.length(); ++k) {
                if (!appeared[s[k] - 'a']) distinct++;
                appeared[s[k] - 'a'] = true;
                dis2[distinct]++;
            }
            for (int i = 0; i <= 26; ++i) count += (dis1[i] * dis2[i]);
        }
        return count;
    }
};