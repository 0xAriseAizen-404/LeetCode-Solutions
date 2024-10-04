class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum & 1 == 1) return false;
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num: nums) {
            for (int j=target; j>=num; --j) {
                if (dp[j - num]) {
                    dp[j] = true;
                    // break;
                }
            }
        }
        return dp[target];
    }
};