// BruteForce Solution
// class Solution {
//     bool valid(const string &s) {
//         int bal = 0;
//         for (char c : s) {
//             bal += (c == '(' ? 1 : -1);
//             if (bal < 0) return false;
//         }
//         return bal == 0;
//     }

//     void genAll(int i, int L, string cur, vector<string> &res) {
//         if (i == L) {
//             if (valid(cur)) res.push_back(cur);
//             return;
//         }
//         genAll(i + 1, L, cur + "(", res);
//         genAll(i + 1, L, cur + ")", res);
//     }

// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         string cur; cur.reserve(2 * n);
//         genAll(0, 2 * n, cur, res);
//         return res;
//     }
// };


// Optimal Solution
class Solution {
private:
    void helper(int opens, int closes, string curr, vector<string> &res) {
        if (opens==0 && closes==0) {
            res.push_back(curr);
            return;
        }
        if (opens > 0) helper(opens-1, closes, curr + "(", res);
        if (opens < closes) helper(opens, closes-1, curr + ")", res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int opens = n;
        helper(opens-1, n, "(", res);
        return res;
    }
};