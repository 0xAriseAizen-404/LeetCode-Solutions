class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        //Transpose
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                mat[i][j] = mat[i][j]^mat[j][i];
                mat[j][i] = mat[i][j]^mat[j][i];
                mat[i][j] = mat[i][j]^mat[j][i];
                //swap(mat[i][j],mat[j][i]);//pre - algorithm
            }
        }
        for(int i=0;i<n;++i)
            reverse(mat[i].begin(),mat[i].end());
    }
};