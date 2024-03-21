class Solution {
public:
    int myPow(long long x, long long n) {
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
        long long result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            n /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenIndices = (n + 1) / 2;
        long long oddIndices = n / 2;
        long long evenCount = myPow(5, evenIndices);
        long long oddCount = myPow(4, oddIndices);
        return (evenCount * oddCount) % 1000000007;
    }
};

    // int countGoodNumbers(long long n) {
    //     // if n = 4 -> _ _ _ _ _
    //     // even indices -> (n+1) / 2
    //     // odd indices -> n / 2
    //     // even numbers count in 0 - 9 => 5
    //     // prime numbers count in 0 - 9 => 4
    //     // if we do a little bit of permutations concept
    //     // pow(5, evenindices) * pow(4, oddindices)
    //     return myPow(5, (n+1)/2)*myPow(4, n/2) % 1000000007;
    // }
