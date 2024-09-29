class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int noOfSubsets = 1 << n;
        vector<vector<int>> res;
        for (int num = 0; num < noOfSubsets; ++num) {
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (num & (1 << i)) v.push_back(nums[i]);
            }
            res.push_back(v);
        }
        sort(res.begin(), res.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a.size() == b.size()) return a < b;
            return a.size() < b.size();
        });
        return res;
    }
};
