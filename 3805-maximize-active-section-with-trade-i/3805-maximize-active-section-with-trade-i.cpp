// CoPilot Solution
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int prevZero = 0, currZero = 0;
        int best = 0;
        bool seenOne = false;
        for (char c : s) {
            if (c == '0') {
                if (seenOne) currZero++;
                else prevZero++;
            } else {
                if (currZero) {
                    prevZero = currZero;
                    currZero = 0;
                }
                if (prevZero) seenOne = true;
            }
            if (currZero)
                best = max(best, prevZero + currZero);
        }
        return ones + best;
    }
};
// TC: O(N)
// SC: O(1)



// // My Solution
// class Solution {
// public:
//     int maxActiveSectionsAfterTrade(string s) {
//         int ones_cnt = 0;
//         for (char &c: s) {
//             if (c == '1') ones_cnt += 1;
//         }
//         int best_zeroes = 0;
//         int left_zeroes = 0;
//         bool had_ones = false;
//         int right_zeroes = 0;
//         for (char &c: s) {
//             if (c == '0') {
//                 if (had_ones) right_zeroes += 1;
//                 else left_zeroes += 1;
//             }
//             if (c == '1') {
//                 if (right_zeroes > 0) {
//                     left_zeroes = right_zeroes;
//                     right_zeroes = 0;
//                 }
//                 if (left_zeroes > 0 && right_zeroes == 0) had_ones = true;
//             }
//             // cout << left_zeroes << " " << right_zeroes << endl;
//             if (right_zeroes > 0)
//                 best_zeroes = max(best_zeroes, left_zeroes + right_zeroes);
//         }
//         return best_zeroes + ones_cnt;
//     }
// };
// TC: O(N)
// SC: O(1)