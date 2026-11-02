class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        // we need to find the smallest prime factor number that divides the 'value'
        // the sequece would be
        // ..., v-p-6, v-p-4, v-p-2, v-p, v, v+p, v+p+2, v+p+4, v+p+6, ...
        if (value == 1) return -1;
        int p = 2; // smallest prime is 2
        while (value % p && p * p <= value) p++;
        if (value % p) p = value; // still unable find a prime factor that divides 'value' then value itself is the smallest prime factor
        if (index) {
            if (index > (value - p) / 2) return -1;
            if (index == n - 1) return value;
        }
        return value + p + 2LL * (n - 1 - index - 1);
    }
};