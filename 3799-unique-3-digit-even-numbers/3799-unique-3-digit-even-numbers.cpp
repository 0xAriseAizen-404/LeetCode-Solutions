class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int digit : digits) freq[digit]++;
        int answer = 0;
        for (int first = 1; first <= 9; first++) {
            for (int second = 0; second <= 9; second++) {
                for (int third = 0; third <= 8; third += 2) {
                    if (freq[first] == 0 || freq[second] == 0 || freq[third] == 0) continue;
                    if (first == second && second == third && freq[first] < 3) continue;
                    if (first == second && freq[first] < 2) continue;
                    if (first == third && freq[first] < 2) continue;
                    if (second == third && freq[second] < 2) continue;
                    answer++;
                }
            }
        }
        return answer;
    }
};

// Wrong Approach
// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         int even_digits_cnt = 0;
//         int zeroes_cnt = 0;
//         int mask = 0;
//         for (int x: digits) {
//             even_digits_cnt += ((x&1) == 0);
//             if ((mask&(1<<x)) == 0) mask = mask | (1<<x);
//             zeroes_cnt += (x == 0);
//         }
//         int unique_cnt = 0;
//         while (mask) {
//             unique_cnt += (mask&1);
//             mask >>= 1;
//         }
//         if (zeroes_cnt > 0)
//             return (unique_cnt - 1 - zeroes_cnt) * (unique_cnt - 1 + zeroes_cnt) * even_digits_cnt;
//         if (unique_cnt == 1) return 1;
//         return (unique_cnt - 1) * (unique_cnt - 1 - 1) * even_digits_cnt;
//     }
// };