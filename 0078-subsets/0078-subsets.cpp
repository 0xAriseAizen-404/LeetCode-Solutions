class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int> item,vector<int> nums, int ind) {
        if (ind >= nums.size()) {
            res.push_back(item);
            return;
        }
        
        helper(res, item, nums, ind+1); // not taking
        
        item.push_back(nums[ind]); // take
        helper(res, item, nums, ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, {}, nums, 0);
        return res;
    }
};