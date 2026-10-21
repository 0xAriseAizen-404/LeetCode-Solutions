class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<int> last_visited = {0, 0};
        int r = 0, c = 0;
        while (r >= 0 && r < rows && c >= 0 && c < cols && !visited[r][c]) {
            visited[r][c] = true;
            last_visited = {r, c};
            if (grid[r][c] == 'U') r -= 1;
            else if (grid[r][c] == 'R') c += 1;
            else if (grid[r][c] == 'L') c -= 1;
            else r += 1;
        }
        return last_visited;
    }
};