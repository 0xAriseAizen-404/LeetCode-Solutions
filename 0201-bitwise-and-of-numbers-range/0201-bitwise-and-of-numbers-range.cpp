class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ne = 0;
        while (left != right) {
            ne += 1;
            left >>= 1;
            right >>= 1;
        }
        return (left << ne);
    }
};