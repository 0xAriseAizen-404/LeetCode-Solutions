class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (left < right) {
            if (vowels.count(s[left]) && vowels.count(s[right])) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            } else {
                if (!vowels.count(s[left])) {
                    left++;
                }
                if (!vowels.count(s[right])) {
                    right--;
                }
            }
        }
        
        return s;
    }
};
