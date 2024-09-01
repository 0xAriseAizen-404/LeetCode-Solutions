class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (original.size() != m*n) return ans;
        for (int i=0; i<m; ++i) {
            vector<int> v;
            for (int j=0; j<n; ++j) v.push_back(original.at(((i * n) + j)));
            ans.push_back(v);
        }
        return ans;
    }
};