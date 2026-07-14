class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // for (int x=0; x<matrix.size(); ++x) {
        //     reverse(matrix[x].begin(), matrix[x].end());
        // }
        // int n = matrix.size();
        // for (int row=0; row<matrix.size(); row++) {
        //     for (int col=0; col<matrix[0].size()-row; col++) {
        //         swap(matrix[row][col], matrix[n-1-col][n-1-row]);
        //     }
        // }

        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = row + 1; col < matrix.size(); ++col) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        for (auto &mat: matrix) reverse(mat.begin(), mat.end());
    }
};
// TC: O(n^2)
// SC: O(1)

// Transpose:
// a[i][j] -> a[j][i]
// (Mirror across the main diagonal)

// 90° Clockwise:
// Transpose + Reverse each row

// 90° Anticlockwise:
// Transpose + Reverse each column

// 180° Rotation:
// Reverse rows + Reverse columns
// OR
// 90° Clockwise + 90° Clockwise
// OR
// 90° Anticlockwise + 90° Anticlockwise