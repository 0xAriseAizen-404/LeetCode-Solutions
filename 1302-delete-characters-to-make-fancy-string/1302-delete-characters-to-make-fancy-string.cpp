class Solution {
public:
    string makeFancyString(string s) {
        int left = 2;
        for (int right = 2; right < s.size(); right++) {
            if (s[right] != s[left - 1] || s[right] != s[left - 2]) {
                s[left++] = s[right];
            }
        }
        return s.substr(0, left);
    }
};