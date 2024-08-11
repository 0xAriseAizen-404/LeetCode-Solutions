class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        long long evenIndices = (n + 1) / 2;
        long long oddIndices = n / 2;
        long long result1 = myPow(5, evenIndices, MOD);
        long long result2 = myPow(4, oddIndices, MOD);
        return (int)((result1 * result2) % MOD);
    }

private:
    long long myPow(long long x, long long n, int MOD) {
        if (n == 0 || x == 1) return 1;
        if (x == 0) return 0;
        x = x % MOD;  // Handle cases where x is greater than MOD
        long long halfPow = myPow((x * x) % MOD, n / 2, MOD);
        return (n % 2 == 0) ? halfPow : (x * halfPow) % MOD;
    }
};
