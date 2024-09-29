class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            string newWord = "";
            for (char c: word) newWord += (char)(c + 1);
            word += newWord;
        }
        return word[k-1];
    }
};