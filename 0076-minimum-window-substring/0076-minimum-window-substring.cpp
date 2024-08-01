class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0 || s.size() < t.size()) return "";

        unordered_map<char, int> mapp;
        for (char x : t) mapp[x]++;

        int required = mapp.size();
        int left = 0, right = 0;
        int got = 0;
        int ans[] = {-1, 0, 0};

        unordered_map<char, int> subStringMap;
        while (right < s.size()) {
            char x = s[right];
            subStringMap[x]++;
            if (mapp.find(x) != mapp.end() && mapp[x] == subStringMap[x]) {
                got++;
            }
            while (left <= right && required == got) {
                x = s[left];
                if (ans[0] == -1 || ans[0] >= (right - left + 1)) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                subStringMap[x]--;
                if (mapp.find(x) != mapp.end() && mapp[x] > subStringMap[x]) {
                    got--;
                }
                left++;
            }
            right++;
        }
        if (ans[0] == -1) return "";
        return s.substr(ans[1], ans[0]);
    }
};
