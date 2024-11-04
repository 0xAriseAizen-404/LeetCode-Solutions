public class Solution {
    public bool IsValidSudoku(char[][] board) {
        var points = new Dictionary<string, int>();
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    string row_key = i.ToString() + " row " + board[i][j];
                    string col_key = j.ToString() + " col " + board[i][j];
                    string grid_key = (i / 3).ToString() + " - " + (j / 3).ToString() + " grid " + board[i][j];
                    
                    if (points.ContainsKey(row_key) || points.ContainsKey(col_key) || points.ContainsKey(grid_key))
                        return false;

                    points[row_key] = 1;
                    points[col_key] = 1;
                    points[grid_key] = 1;
                }
            }
        }
        return true;
    }
}
