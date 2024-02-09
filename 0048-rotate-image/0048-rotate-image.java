import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public void rotate(int[][] mat) {
        int n = mat.length;

        // Transpose
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mat[i][j] = mat[i][j] ^ mat[j][i];
                mat[j][i] = mat[i][j] ^ mat[j][i];
                mat[i][j] = mat[i][j] ^ mat[j][i];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                int temp = mat[i][start];
                mat[i][start] = mat[i][end];
                mat[i][end] = temp;
                start++;
                end--;
            }
        }

        // Reverse each row
        // for (int i = 0; i < n; ++i) {
            // List<Integer> rowList = Arrays.asList(Arrays.stream(mat[i]).boxed().toArray(Integer[]::new));
            // Collections.reverse(Arrays.asList(mat[i]));
            // mat[i] = rowList.stream().mapToInt(Integer::intValue).toArray();
        // }
    }
}
