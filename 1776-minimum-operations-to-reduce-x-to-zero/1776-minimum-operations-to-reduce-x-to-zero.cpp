class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        int left = 0, sum = 0;
        int longest = -1;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > target) sum -= nums[left++];
            if (sum == target) longest = max(longest, right - left + 1);
        }
        return longest == -1 ? -1 : nums.size() - longest;
    }
};

// class Solution {
// public:
//     int minOperations(vector<int>& nums, int x) {
//         int n = nums.size();
//         int sum = 0;
//         int left = 0;
//         int ans = INT_MAX;
//         // Take prefix
//         while (left < n && sum + nums[left] <= x) {
//             sum += nums[left];
//             left++;
//         }
//         if (sum == x) ans = left;
//         int right = n - 1;
//         // Replace left picks with right picks
//         while (left > 0) {
//             sum -= nums[--left];
//             while (right >= 0 && sum < x) {
//                 sum += nums[right];
//                 right--;
//             }
//             if (sum == x) {
//                 int leftOps = left;
//                 int rightOps = n - 1 - right;
//                 ans = min(ans, leftOps + rightOps);
//             }
//         }
//         return ans == INT_MAX ? -1 : ans;
//     }
// };