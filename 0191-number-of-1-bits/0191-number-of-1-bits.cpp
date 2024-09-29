class Solution {
public:
    int hammingWeight(int n) {
        // int cnt = 0;
        // for (int i=0; i<32; ++i) {
        //     if (n & (1 << i)) cnt++;
        // }
        // return cnt;

        // return __builtin_popcount(n);

        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};