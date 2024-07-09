class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();

        int wi = 0, i = 0;
        int wj = 0, j = 0;

        while (wi < m && wj < n) {
            if (word1[wi][i++] != word2[wj][j++]) return false;
            if (i == word1[wi].length()) { wi++; i = 0; }
            if (j == word2[wj].length()) { wj++; j = 0; }
        }
        if (wi == m && wj == n) return true;
        return false;
    }
};