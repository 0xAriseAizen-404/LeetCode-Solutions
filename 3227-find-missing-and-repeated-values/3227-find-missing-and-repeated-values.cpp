class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int x = 1;
        long long gridSum = 0, gridSqSum = 0;
        long long perfectSum = 0, perfectSqSum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                gridSum += grid[i][j];
                gridSqSum += static_cast<long long>(grid[i][j] * grid[i][j]);

                perfectSum += x;
                perfectSqSum += x * x;
                x += 1;
            }
        }
        int sumDiff = gridSum - perfectSum;
        int sqSumDiff = gridSqSum - perfectSqSum;
        vector<int> res(2, 0);
        res.at(0) = ((sqSumDiff / sumDiff) + sumDiff) / 2;
        res.at(1) = ((sqSumDiff / sumDiff) - sumDiff) / 2;
        return res;
    }
};