class Solution {
private:
    void myHelper(vector<vector<int>> &res, vector<int> &help, vector<int> &nums, int ind) {
        if (ind == nums.size()) {
            res.push_back(help);
            return;
        }
        help.push_back(nums[ind]);
        myHelper(res, help, nums, ind + 1);
        help.pop_back();

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) ind += 1;
        myHelper(res, help, nums, ind + 1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> help;
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return a < b;
        });
        myHelper(res, help, nums, 0);
        return res;
    }
};