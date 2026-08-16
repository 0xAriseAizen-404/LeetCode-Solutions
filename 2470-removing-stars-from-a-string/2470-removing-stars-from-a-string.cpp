class Solution {
public:
    string removeStars(string s) {
        int left = 0;
        int right = 0;
        int sz = s.length();
        while (right < sz) {
            if (s[right] != '*') s[left++] = s[right];
            else left--;
            right += 1;
        }
        return s.substr(0, left);
    }
};

// class Solution {
// public:
//     string removeStars(string s) {
//         string res = "";
//         for(char ch: s) {
//             if (ch != '*') res.push_back(ch);
//             else {
//                 if (!res.empty()) res.pop_back();
//             }
//         }
//         return res;
//     }
// };