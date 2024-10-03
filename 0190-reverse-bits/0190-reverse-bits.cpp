class Solution {
public:
    uint32_t reverseBits(uint32_t x) {
        uint32_t res = 0;
        for (int i=0; i<32; ++i) {
            if (x & (1 << i)) res |= (1 << (31 - i));
        }
        return res;
    }
};