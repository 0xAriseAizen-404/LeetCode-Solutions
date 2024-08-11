class Solution {
    private static final int MOD = 1000000007;

    public int countGoodNumbers(long n) {
        long evenIndices = (n + 1) / 2;
        long oddIndices = n / 2;
        return (int) ((myPow(5, evenIndices) * myPow(4, oddIndices)) % MOD);
    }

    private long myPow(long x, long n) {
        if (n == 0) return 1;
        long result = 1;
        x = x % MOD;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;
            n /= 2;
        }
        return result;
    }
}
