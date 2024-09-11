class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int ones = 0;
        while (diff > 0) {
            ones += (diff & 1);
            diff >>= 1;
        }
        return ones;
    }
};