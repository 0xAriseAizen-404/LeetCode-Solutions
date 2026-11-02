class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int min_val = INT_MAX;
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            int merged = nums[i];
            int val = nums[i + 1];
            if (1 <= val && val <= 9) merged = merged * 10 + val;
            else if (10 <= val && val <= 99) merged = merged * 100 + val;
            else if (100 <= val && val <= 999) merged = merged * 1000 + val;
            else merged = merged * 10000 + val;
            min_val = min(min_val, merged);
        }
        return min_val;
    }
};

// class Solution {
// public:
//     int minMergedInteger(vector<int>& nums) {
//         int min_val = INT_MAX;
//         for (int i = 0; i + 1 < nums.size(); i += 2) {
//             string a = to_string(nums[i]);
//             string b = to_string(nums[i + 1]);
//             int merged = stoi(a + b);
//             min_val = min (min_val, merged);
//         }
//         return min_val;
//     }
// };

// class Solution {
// public:
//     int minMergedInteger(vector<int>& nums) {
//         int ans = INT_MAX;
//         for (int i = 0; i + 1 < nums.size(); i += 2) {
//             int rev = 0;
//             int x = nums[i + 1];
//             while (x) {
//                 rev = rev * 10 + x % 10;
//                 x /= 10;
//             }
//             int merged = nums[i];
//             while (rev) {
//                 merged = merged * 10 + rev % 10;
//                 rev /= 10;
//             }
//             ans = min(ans, merged);
//         }
//         return ans;
//     }
// };