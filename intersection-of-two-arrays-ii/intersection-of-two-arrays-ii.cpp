class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        vector<int> ans;
        unordered_map<int, int> umap;
        for (auto& x: nums1) umap[x]++;
        for (auto& x: nums2) {
            if (umap[x] != 0) {
                ans.emplace_back(x);
                umap[x] -= 1;
            }
        }
        return ans;
    }
};