class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < nums.size(); right++) {
            umap[nums[right]] += 1;
            while (umap[nums[right]] > k) {
                umap[nums[left++]] -= 1;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};