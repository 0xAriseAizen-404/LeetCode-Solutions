class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        backTrack(res, combination, 0, candidates, target);
        return res;
    }
    void backTrack(vector<vector<int>> &res, vector<int> &combination, int startInd, vector<int> &candidates, int target) {
        if (target == 0) res.push_back(combination);
        if (target < 0) return;
        for (int i = startInd; i<candidates.size(); i++) {
            combination.push_back(candidates[i]);
            backTrack(res, combination, i, candidates, target - candidates[i]);
            combination.pop_back();
        }
    }
};