class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i=0; i<nums.size(); ++i) {
            if (umap.find(target - nums[i]) != umap.end()) 
                return {umap[(target - nums[i])], i + 1};
            umap[nums[i]] = i + 1;
        }
        return {-1, -1};
    }
};