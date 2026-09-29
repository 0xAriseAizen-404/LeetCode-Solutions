class Solution {
private:
    int m, n;
    vector<vector<vector<int>>> dp;
    bool helper(vector<vector<char>>& grid, int row, int col, int balance) {
        if (row >= m || col >= n) return false;
        if (grid[row][col] == '(') balance++;
        else balance--;
        if (balance < 0) return false;
        int remaining = (m - 1 - row) + (n - 1 - col);
        if (balance > remaining) return false;
        if (row == m - 1 && col == n - 1) return balance == 0;
        // Already calculated
        if (dp[row][col][balance] != -1) return dp[row][col][balance];
        return dp[row][col][balance] = helper(grid, row + 1, col, balance) || helper(grid, row, col + 1, balance);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') return false;
        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        return helper(grid, 0, 0, 0);
    }
};


// TLE
// class Solution {
// private:
//     int m, n;
//     bool helper(vector<vector<char>>& grid, int row, int col, int balance) {
//         if (row >= m || col >= n) return false;
//         if (grid[row][col] == '(') balance++;
//         else balance--;
//         if (balance < 0) return false;
//         // Number of cells remaining after this one
//         int remaining = (m - 1 - row) + (n - 1 - col);
//         // Even if all remaining cells are '(', we cannot reach balance 0
//         if (balance > remaining) return false;
//         // Destination
//         if (row == m - 1 && col == n - 1) return balance == 0;
//         return helper(grid, row + 1, col, balance) || helper(grid, row, col + 1, balance);
//     }

// public:
//     bool hasValidPath(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         // A valid path has m+n-1 characters, which must be even.
//         if ((m + n - 1) % 2 != 0) return false;
//         // A valid path must start with '(' and end with ')'.
//         if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') return false;
//         return helper(grid, 0, 0, 0);
//     }
// };

// My Version - MLE
// class Solution {
// private:
//     bool helper(vector<vector<char>>& grid, int row, int col, string path, int opens) {
//         if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return false;
//         if (grid[row][col] == '(') opens++;
//         else opens--;
//         if (opens < 0) return false;
//         path.push_back(grid[row][col]);
//         if (row == grid.size() - 1 && col == grid[0].size() - 1) return opens == 0;
//         return helper(grid, row + 1, col, path, opens) || helper(grid, row, col + 1, path, opens);
//     }
// public:
//     bool hasValidPath(vector<vector<char>>& grid) {
//         return helper(grid, 0, 0, "", 0);
//     }
// };