class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int, int> umap;
        vector<int> ans;
        for (auto& x: nums) {
            if (umap[x] != 0)
                ans.emplace_back(x);
            else
                umap[x]++;
        }
        return ans;
        
//         int n = nums.size();
//         vector<int> ans;
        
//         if (n < 2) return ans;
        
//         for (int i=0; i<n; ++i) {
//             int index = abs(nums[i]) - 1;
//             if (nums[index] < 0) ans.push_back(index + 1);
//             else nums[index] = -nums[index];
//         }
//         for (int i=0; i<n; ++i)
//             nums[i] = abs(nums[i]);
        
//         return ans;
    }
};