// My Version
// class Solution {
// public:
//     long long countCommas(long long n) {
//         if (n < 1000) return 0;
//         long long total = 0;

//         if (n < 1e+6) return 1 * (n - 999);
//         if (1e+6 <= n) {
//             total += 1 * (1e+6 - (1e+3));
//             if (n < 1e+9) return total + 2 * (n - (1e+6 - 1));
//         }
//         if (1e+9 <= n) {
//             total += 2 * (1e+9 - (1e+6));
//             if (n < 1e+12) return total + 3 * (n - (1e+9 - 1));
//         }
//         if (1e+12 <= n) {
//             total += 3 * (1e+12 - (1e+9));
//             if (n < 1e+15) return total + 4 * (n - (1e+12 - 1));
//         }
//         if (1e+15 <= n) { 
//             total += 4 * (1e+15 - 1e+12); 
//             return total + 5 * (n - (1e+15 - 1)); 
//         }
//         return total;
//     }
// };

// ChatGPT Version
class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;

        long long total = 0;

        if (n < 1000000LL)
            return n - 999;

        // 1000 to 999999
        total += 999000LL;

        if (n < 1000000000LL)
            return total + 2LL * (n - 999999);

        // 1000000 to 999999999
        total += 2LL * 999000000LL;

        if (n < 1000000000000LL)
            return total + 3LL * (n - 999999999);

        // 1000000000 to 999999999999
        total += 3LL * 999000000000LL;

        if (n < 1000000000000000LL)
            return total + 4LL * (n - 999999999999);

        // 1000000000000 to 999999999999999
        total += 4LL * 999000000000000LL;

        return total + 5LL * (n - 999999999999999LL);
    }
};