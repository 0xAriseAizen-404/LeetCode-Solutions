class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int rem_10 = 1;
        int sum_digits = 0;
        while (n) {
            int rem = n % 10;
            n /= 10;
            if (!rem) continue;
            x = rem * rem_10 + x;
            sum_digits += rem;
            rem_10 *= 10;
        }
        return x * sum_digits;
    }
};