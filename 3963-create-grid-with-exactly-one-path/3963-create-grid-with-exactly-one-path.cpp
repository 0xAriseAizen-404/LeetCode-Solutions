class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        for (int i = 0; i < n; ++i) grid[0][i] = '.';
        for (int i = 0; i < m; ++i) grid[i][n - 1] = '.';
        return grid;
    }
};

// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {
//         vector<string> grid;
//         for (int i = 0; i < m; ++i) {
//             if (i == 0) {
//                 string path = "";
//                 for (int i = 0; i < n; ++i) path += ".";
//                 grid.push_back(path);
//             } else {
//                 string path = "";
//                 for (int i = 0; i < n - 1; ++i) path += "#";
//                 path += ".";
//                 grid.push_back(path);
//             }
//         }
//         return grid;
//     }
// };