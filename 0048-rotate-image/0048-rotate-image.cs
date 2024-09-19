public class Solution {
    public void Rotate(int[][] mat) {
        int n = mat.GetLength(0);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mat[i][j] = mat[i][j] ^ mat[j][i];
                mat[j][i] = mat[i][j] ^ mat[j][i];
                mat[i][j] = mat[i][j] ^ mat[j][i];
            }
        }
        for (int i = 0; i < n; ++i) {
            Array.Reverse(mat[i]);
        }
    }
}
