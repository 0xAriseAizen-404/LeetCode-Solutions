class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        function<int(int, int)> sink = [&](int r, int c) -> int {
            if (r < 0 || r >= m || c < 0 || c >= n) return 0; // touches the border; out of bounds;
            if (grid[r][c] == 1) return 1; // water, or land we already sinked
            grid[r][c] = 1; // visited, sink it
            return sink(r + 1, c)
                    & sink(r - 1, c)
                    & sink(r, c + 1)
                    & sink(r, c - 1);
        };
        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) ans += sink(r, c);
            }
        }
        return ans;
    }
};

// DFS + Sink Logic (here, modifying the grid)
// class Solution {
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         auto sink = [&](auto&& self, int r, int c) -> void {
//             if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1) return;
//             grid[r][c] = 1;
//             self(self, r + 1, c);
//             self(self, r - 1, c);
//             self(self, r, c + 1);
//             self(self, r, c - 1);
//         };
//         for (int r = 0; r < m; ++r) {
//             sink(sink, r, 0); // left edge
//             sink(sink, r, n - 1); // right edge
//         }
//         for (int c = 0; c < n; ++c) {
//             sink(sink, 0, c); // top edge
//             sink(sink, m - 1, c); // botton edge
//         }
//         int ans = 0;
//         for (int r = 1; r < m - 1; ++r) {
//             for (int c = 1; c < n - 1; ++c) {
//                 if (grid[r][c] == 0) {
//                     ans += 1;
//                     sink(sink, r, c);
//                 }
//             }
//         }
//         return ans;
//     }
// };
// TC: O(M*N)
// SC: O(1)

// Pure DFS + Visited
// class Solution {
// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         struct pairHash {
//             size_t operator()(const pair<int,int>& p) const {
//                 return p.first * 31 + p.second;
//             }
//         };
//         unordered_set<pair<int, int>, pairHash> visited;

//         // can use like this also
//         // unordered_set<long long> vis;
//         // auto key = 1LL * r * n + c;
        
//         auto sink = [&](auto&& self, int r, int c) -> int {
//             if (r < 0 || r >= m || c < 0 || c >= n) return 0;
//             if (grid[r][c] == 1 || visited.count({r, c}) > 0) return 1;
//             visited.insert({r, c});
//             return self(self, r + 1, c) 
//                     & self(self, r - 1, c) 
//                     & self(self, r, c + 1) 
//                     & self(self, r, c - 1); 
//             // & (not &&) -> 1 & 1 & 1 & 1 = 1 || 1 & 1 & 1 & 0 = 0. like this logic. better trick right ?
//             // If dfs(a) returns 0, the remaining DFS calls are skipped, leaving part of the island unvisited. Then those cells may be visited again later, causing incorrect counting.
//         };
//         int ans = 0;
//         for (int r = 0; r < m; ++r) {
//             for (int c = 0; c < n; ++c) {
//                 if (grid[r][c] == 0 && visited.count({r, c}) == 0)
//                     ans += sink(sink, r, c);
//             }
//         }
//         return ans;
//     }
// };
// TC: O(N*M)
// SC: O(N*M)