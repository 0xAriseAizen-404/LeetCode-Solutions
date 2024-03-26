class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;
        for (auto& x: nums) umap[x]++;
        for (int i=1; i<=n; ++i)
            if (umap[i] == 0)
                return i;
        return n + 1;
    }
};