class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int idx_low = 0;
        int idx_high = nums.size() - 1;

        while(nums[idx_low] + nums[idx_high] != target) {
        if(nums[idx_low] + nums[idx_high] > target) --idx_high;
        else ++idx_low;
        }

        return {idx_low + 1, idx_high + 1};

        // unordered_map<int, int> umap;
        // for (int i=0; i<nums.size(); ++i) {
        //     if (umap.find(target - nums[i]) != umap.end()) 
        //         return {umap[(target - nums[i])], i + 1};
        //     umap[nums[i]] = i + 1;
        // }
        // return {-1, -1};
    }
};