class Solution {
public:
    bool isValid(string s) {
        int opens = 0;
        for (char c : s) {
            if (c == '(') opens++;
            else if (c == ')') {
                if (opens == 0) return false;
                opens--;
            }
        }
        return opens == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);
        bool found = false;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (isValid(cur)) {
                res.push_back(cur);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string nxt = cur.substr(0, i) + cur.substr(i + 1);
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        return res;
    }
};

// class Solution {
// private:
//     bool valid(string s) {
//         int openss = 0;
//         for (char ch : s) {
//             if (ch == '(') opens++;
//             else if (ch == ')') {
//                 if (opens == 0) return false;
//                 opens--;
//             }
//         }
//         return opens == 0;
//     }
//     void helper(string& s, int idx, string cur, unordered_set<string>& ans, int& bestLen) {
//         if (idx == s.size()) {
//             if (!valid(cur)) return;
//             if ((int)cur.size() > bestLen) {
//                 bestLen = cur.size();
//                 ans.clear();
//             }
//             if ((int)cur.size() == bestLen) ans.insert(cur);
//             return;
//         }
//         if (s[idx] != '(' && s[idx] != ')') {
//             helper(s, idx + 1, cur + s[idx], ans, bestLen);
//         }
//         else {
//             helper(s, idx + 1, cur + s[idx], ans, bestLen);
//             helper(s, idx + 1, cur, ans, bestLen);
//         }
//     }

// public:
//     vector<string> removeInvalidParentheses(string s) {
//         unordered_set<string> ans;
//         int bestLen = -1;
//         helper(s, 0, "", ans, bestLen);
//         return vector<string>(ans.begin(), ans.end());
//     }
// };