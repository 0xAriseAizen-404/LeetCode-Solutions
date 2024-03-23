class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); ++i) {
            if (umap.count(nums[i]) > 0 && abs(umap[nums[i]] - i) <= k) 
                return true;
            umap[nums[i]] = i;
        }
        return false;
    }
};