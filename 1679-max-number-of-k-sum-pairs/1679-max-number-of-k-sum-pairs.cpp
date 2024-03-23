class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> umap;
        for(auto& x: nums) {
            int rem = k - x;
            if(umap[rem] != 0) {
                ans++;
                if(umap[rem] == 1)
                    umap.erase(rem);
                else
                    umap[rem]--;
            } else {
                umap[x]++;
            }
        }
        return ans;
    }
};