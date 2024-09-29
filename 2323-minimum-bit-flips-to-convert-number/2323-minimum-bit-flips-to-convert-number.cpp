class Solution {
public:
    int minBitFlips(int start, int goal) {
        // return __builtin_popcount(start ^ goal);
        int notEqualBits_cnt = 0;
        for (int i=0; i<32; ++i) {
            if ((start&(1 << i)) != (goal&(1 << i)))
                notEqualBits_cnt += 1;
        }
        return notEqualBits_cnt;
    }
};