class Solution {
private:
    int binarySearch(vector<int> &dp, int target) {
        int low = 0;
        int high = dp.size() - 1;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (dp[mid] == target) return mid;
            else if (dp[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i=1; i<nums.size(); ++i) {
            if (dp.back() < nums[i]) dp.push_back(nums[i]);
            else {
                int indToInsert = binarySearch(dp, nums[i]);
                dp[indToInsert] = nums[i];
            }
        }
        return dp.size();
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         int maxLen = 1;
//         vector<int> dp(n, 1);
//         for (int i=1; i<n; ++i) {
//             for (int j=0; j<i; ++j) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], 1 + dp[j]);
//                     maxLen = max(maxLen, dp[i]);
//                 }
//             }
//         }
//         return maxLen;
//     }
// };