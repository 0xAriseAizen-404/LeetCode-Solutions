// class Solution {
// public:
//     vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
//         vector<vector<int>> ans;
//         if (original.size() != m*n) return ans;
//         for (int i=0; i<m; ++i) {
//             vector<int> v;
//             for (int j=0; j<n; ++j) v.push_back(original.at(((i * n) + j)));
//             ans.push_back(v);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        if(m*n!=original.size()){
            return {};
        }
        vector<vector<int>>ans(m,vector<int>(n,0));
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[k++];
               
            }
        }
        return ans;
    }
};