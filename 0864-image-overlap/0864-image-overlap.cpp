class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;
        int n = img1.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < ones1.size(); i++){
            for(int j = 0; j < ones2.size(); j++){
                int dx = ones1[i].first - ones2[j].first;
                int dy = ones1[i].second - ones2[j].second;
                int hash_key = dx * 100 + dy; 
                mp[hash_key]++;
            }
        }
        int ans = 0;
        for(auto& m : mp){
            if(m.second > ans){
                ans = m.second;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
//         int n = img1.size();
//         int ans = 0;
//         // Try every possible row shift
//         for (int dr = -(n - 1); dr <= n - 1; ++dr) {
//             // Try every possible column shift
//             for (int dc = -(n - 1); dc <= n - 1; ++dc) {
//                 int overlap = 0;
//                 for (int i = 0; i < n; ++i) {
//                     for (int j = 0; j < n; ++j) {
//                         int ni = i + dr;
//                         int nj = j + dc;
//                         // Translated position must remain inside img2
//                         if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
//                             if (img1[i][j] == 1 && img2[ni][nj] == 1) ++overlap;
//                         }
//                     }
//                 }
//                 ans = max(ans, overlap);
//             }
//         }
//         return ans;
//     }
// };