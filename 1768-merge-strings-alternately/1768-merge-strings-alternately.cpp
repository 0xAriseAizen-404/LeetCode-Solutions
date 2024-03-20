class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        string sb = "";
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            sb += word1[i];
            sb += word2[j];
            i++;
            j++;
        }
        if (i < n1)  sb += word1.substr(i);
        else if (j < n2) sb += word2.substr(j);
        return sb;
    }
};