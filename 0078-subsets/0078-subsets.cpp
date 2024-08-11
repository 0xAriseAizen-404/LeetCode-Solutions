class Solution {
private:
    void myHelper(vector<vector<int>> &res, vector<int> &nums, int ind, vector<int> &help) {
        if (ind == nums.size()) {
            res.push_back(help);
            return;
        }
        myHelper(res, nums, ind + 1, help);
        help.push_back(nums[ind]);
        myHelper(res, nums, ind + 1, help);
        // Backtrack
        help.pop_back(); // bcoz we used '&' in formal parameter its an address
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> help;
        myHelper(res, nums, 0, help);
        return res;
    }
};
