class Solution {
private:
    bool solve(vector<vector<int>>& grid, int health, vector<vector<int>>& best, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return false;
        if (grid[row][col] == 1) health--;
        if (health < 1) return false;
        if (health <= best[row][col]) return false;
        best[row][col] = health;
        if (row == grid.size() - 1 && col == grid[0].size() - 1) return true;

        return solve(grid, health, best, row + 1, col) ||
               solve(grid, health, best, row - 1, col) ||
               solve(grid, health, best, row, col + 1) ||
               solve(grid, health, best, row, col - 1);
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> best(m, vector<int>(n, -1));
        return solve(grid, health, best, 0, 0);
    }
};

// class Solution {
// private:
//     bool solve(vector<vector<int>> &grid, int health, vector<vector<bool>> &visited, int row, int col) {
//         if (row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0) return false;
//         if (visited[row][col]) return false;
//         if (grid[row][col] == 1) health--;
//         if (health < 1) return false;
//         if (row == grid.size()-1 && col == grid[0].size()-1) return true;
//         visited[row][col] = true;
//         bool solved = solve(grid, health, visited, row + 1, col) ||
//                 solve(grid, health, visited, row - 1, col) ||
//                 solve(grid, health, visited, row, col + 1) ||
//                 solve(grid, health, visited, row, col - 1);
//         if (solved) return true;
//         visited[row][col] = false;
//         return false;
//     }
// public:
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         vector<vector<bool>> visited;
//         for (int i=0; i<grid.size(); ++i) {
//             vector<bool> v(grid[0].size(), false);
//             visited.push_back(v);
//         }

//         return solve(grid, health, visited, 0, 0);
//     }
// };