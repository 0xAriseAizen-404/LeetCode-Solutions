// DFS + Connceted_Graphs + Modifying the grid itself
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        auto dfs = [&](auto&& self, int r, int c) -> long long {
            if (r < 0 || r >= m || c < 0 || c >= n || !grid[r][c]) return 0LL;
            long long rem = grid[r][c] % k;
            grid[r][c] = 0; // visited
            rem = (rem + self(self, r + 1, c)) % k;
            rem = (rem + self(self, r - 1, c)) % k;
            rem = (rem + self(self, r, c + 1)) % k;
            rem = (rem + self(self, r, c - 1)) % k;
            return rem;
        };
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) ans += (dfs(dfs, r, c) == 0);
            }
        }
        return ans;
    }
};
// TC: O(N*M)
// SC: O(1)

// DFS + Connected_Graphs + Visited Tracking
// class Solution {
// public:
//     int countIslands(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int ans = 0;
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
        
//         auto dfs = [&](auto&& self, int r, int c) -> long long {
//             if (r < 0 || r >= m || c < 0 || c >= n) return 0LL; // touches the border; out of bounds;
//             if (grid[r][c] == 0 || visited[r][c]) return 0LL; // water; or visited;
//             visited[r][c] = true;
//             long long rem = grid[r][c] % k;
//             rem = (rem + self(self, r + 1, c)) % k;
//             rem = (rem + self(self, r - 1, c)) % k;
//             rem = (rem + self(self, r, c + 1)) % k;
//             rem = (rem + self(self, r, c - 1)) % k;
//             return rem;
//         };
//         for (int r = 0; r < m; ++r) {
//             for (int c = 0; c < n; ++c) {
//                 if (grid[r][c] && !visited[r][c]) ans += (dfs(dfs, r, c) == 0);
//             }
//         }
//         return ans;
//     }
// };
// TC: O(N*M)
// SC: O(N*M)