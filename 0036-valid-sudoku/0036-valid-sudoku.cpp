class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<char, int>> map;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cell = board[i][j];
                if (cell != '.') {
                    if (map[i][cell]++ > 0)
                        return false;
                    if (map[j + 9][cell]++ > 0)
                        return false;
                    if (map[(i / 3) * 3 + (j / 3) + 18][cell]++)
                        return false;
                }
            }
        }
        return true;
    }
};