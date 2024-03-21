class Solution {
    static int myPow(long x, long n) {
        int mod = 1000000007;
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }
        if (n < 0) {
            return myPow(1 / x, -n);
        }
        int result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (int)((result * x) % mod);
            }
            x = (x * x) % mod;
            n /= 2;
        }
        return result;
    }

    public int countGoodNumbers(long n) {
        long evenIndices = (n + 1) / 2;
        long oddIndices = n / 2;
        long evenCount = myPow(5, evenIndices);
        long oddCount = myPow(4, oddIndices);
        return (int)((evenCount * oddCount) % 1000000007);
    }
}
