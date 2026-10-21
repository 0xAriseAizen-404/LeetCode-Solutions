class Solution {
public:
    int minDeletions(vector<int>& nums) {
        // x ^ y != 0 is the condition, this is what we have to look for
        // that means edge case is  x ^ y = 0, is the case that triggers
        // x ^ y = 0
        // x ^ y ^ y = 0 ^ y
        // x = y
        // the adjacent indices where x == y, is the case we have to delete one of them
        // 3 3 3 3 -> delete three 3's
        // 3 3 3 2 1 6 6 3 3 => 3 2 1 6 3
        // delete sz-1 in the consecutive space or cluster
        int sz = 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) sz++;
            else {
                ans += sz;
                sz = 0;
            }
        }
        return ans + sz;
    }
};