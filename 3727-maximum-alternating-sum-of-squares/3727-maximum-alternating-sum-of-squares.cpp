// class Solution {
// public:
//     long long maxAlternatingSum(vector<int>& nums) {
//         for (auto& it: nums) {
//             if (it < 0) it = -it;
//         }
//         sort(nums.begin(), nums.end());
//         int low = 0, high = nums.size() - 1;
//         long long ans = 0;
//         while (low < high) {
//             ans += 1LL * nums[high] * nums[high];
//             ans -= 1LL * nums[low] * nums[low];
//             low++; high--;
//         }
//         if (low == high) ans += 1LL * nums[high] * nums[high];
//         return ans;
//     }
// };

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for (int x : nums) sq.push_back(1LL * x * x);
        int h = sq.size() / 2;
        nth_element(sq.begin(), sq.begin() + h, sq.end());  // quickselect: the smallest half in front, any order
        long long total = accumulate(sq.begin(), sq.end(), 0LL);
        long long small = accumulate(sq.begin(), sq.begin() + h, 0LL);
        return total - 2 * small;
        // Largest - Smallest
        // largest = total - small
        // smallest = small
        // total - small - small = total - 2 * small
    }
};