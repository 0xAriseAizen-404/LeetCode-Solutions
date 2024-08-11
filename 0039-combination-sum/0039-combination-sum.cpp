class Solution {
private:
    void myHelper(vector<vector<int>> &res, vector<int> &help, vector<int> &candidates, int target, int currSum, int ind) {
        if (currSum == target) {
            res.push_back(help);
            return; // Stop further recursion once target is reached
        }
        if (currSum > target || ind == candidates.size()) {
            return;
        }
        // Not take
        myHelper(res, help, candidates, target, currSum, ind + 1);
        // Take
        help.push_back(candidates[ind]);
        myHelper(res, help, candidates, target, currSum + candidates[ind], ind);
        // Backtrack
        help.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> help;
        myHelper(res, help, candidates, target, 0, 0);
        return res;
    }
};
