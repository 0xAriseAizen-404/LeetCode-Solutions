class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_ones = -1, max_row = 0;
        for (int i = 0; i < mat.size(); ++i) {
            int cnt_ones = 0;
            for (int j = 0; j < mat[i].size(); ++j) {
                cnt_ones += mat[i][j];
            }
            if (cnt_ones > max_ones) {
                max_ones = cnt_ones;
                max_row = i;
            }
        }
        return {max_row, max_ones};
    }
};