class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sz = nums.size();
        int totalXor = 0;
        bool allZero = true;
        for (int x: nums) {
            totalXor ^= x;
            if (x > 0) allZero = false;
        }
        if (totalXor > 0) return sz;
        return allZero ? 0 : sz - 1;
    }
};