class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        List<int[]> positions = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    positions.add(new int[]{i, j});
                }
            }
        }

        for (int[] pos : positions) {
            for (int i = 0; i < m; ++i) {
                matrix[pos[0]][i] = 0;
            }

            for (int j = 0; j < n; ++j) {
                matrix[j][pos[1]] = 0;
            }
        }
    }
}