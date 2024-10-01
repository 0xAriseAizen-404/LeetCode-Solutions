class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> map;
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                char currVal = board[i][j];
                if(currVal != '.') {
                    string row_key = to_string(i) + "row" + currVal;
                    string col_key = to_string(j) + "col" + currVal;
                    string grid_key = to_string(i/3) + "-" + to_string(j/3) + "grid" + currVal;
                    if(map[row_key] != 0 || map[col_key] != 0 || map[grid_key] != 0) return false;
                    else 
                        map[row_key]++;
                        map[col_key]++;
                        map[grid_key]++;
                    }
                }
            }
        return true;
    }
};
