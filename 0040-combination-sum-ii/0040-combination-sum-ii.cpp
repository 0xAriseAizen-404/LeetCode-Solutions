class Solution {
private:
    void myHelper(vector<vector<int>> &res, vector<int> &help, vector<int> &candidates, int target, int currSum, int ind) {
        if (currSum == target) {
            res.push_back(help);
            return; // Stop further recursion once target is reached
        }
        if (currSum > target || ind >= candidates.size()) {
            return;
        }

        for (int i = ind; i < candidates.size(); ++i) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            
            help.push_back(candidates[i]);
            myHelper(res, help, candidates, target, currSum + candidates[i], i + 1);
            help.pop_back();
        }
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
