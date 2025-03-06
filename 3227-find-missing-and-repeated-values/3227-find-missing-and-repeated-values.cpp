class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrSum = 0;
        long long n = grid.size();
        long long total = n * n;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                sum += grid[row][col];
                sqrSum += static_cast<long long>(grid[row][col]) * grid[row][col];
            }
        }

        long long expectedSum = total * (total + 1) / 2;
        long long expectedSqrSum = total * (total + 1) * (2 * total + 1) / 6;

        long long sumDiff = sum - expectedSum;       
        long long sqrDiff = sqrSum - expectedSqrSum;

        int repeated = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = repeated - sumDiff;

        return {repeated, missing};
    }
};
