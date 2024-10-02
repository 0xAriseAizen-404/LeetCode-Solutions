class Solution {
private:
    void myHelper(vector<vector<int>> &res, vector<int> &help, vector<int> &candidates, int target, int currSum, int ind) {
        if (currSum == target) {
            res.push_back(help);
            return;
        }
        if (currSum > target || ind >= candidates.size()) return;

        help.push_back(candidates[ind]);
        myHelper(res, help, candidates, target, currSum + candidates[ind], ind + 1);
        help.pop_back();

        while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1]) ind += 1;
        myHelper(res, help, candidates, target, currSum, ind + 1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> help;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        myHelper(res, help, candidates, target, 0, 0);
        return res;
    }
};
