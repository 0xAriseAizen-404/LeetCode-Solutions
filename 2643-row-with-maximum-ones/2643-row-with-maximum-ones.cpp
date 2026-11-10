class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCnt = 0;
        int idx = 0;

        for(int i = 0; i < mat.size(); ++i){
            int currCnt = accumulate(mat[i].begin(), mat[i].end(), 0);
            if(currCnt > maxCnt){
                maxCnt = currCnt;
                idx = i;
            }
        }
        return {idx, maxCnt};
    }
};