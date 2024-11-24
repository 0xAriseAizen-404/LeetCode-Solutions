class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long summ = 0;
        int minAbsVal = INT_MAX, cntNeg = 0;
        for (auto &row: matrix) {
            for (int &x: row) {
                minAbsVal = min(minAbsVal, abs(x));
                if (x < 0) {
                    summ -= x;
                    cntNeg++;
                } else {
                    summ += x;
                }
            }
        }
        return (cntNeg & 1) ? summ - 2 * minAbsVal : summ;
    }
};