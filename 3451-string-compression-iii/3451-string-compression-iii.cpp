class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        for (int i=1; i<word.size(); ++i) {
            if (count == 9 || word[i] != word[i-1]) {
                comp += (to_string(count) + word[i-1]);
                count = 0;
            }
            count++;
        }
        comp += (to_string(count) + word.back());
        return comp;
    }
};