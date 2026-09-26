class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int pos = 0; pos < s.length(); ++pos) {
            ans += (pos + 1) * ('z' - s[pos] + 1);
        }
        return ans;
    }
};