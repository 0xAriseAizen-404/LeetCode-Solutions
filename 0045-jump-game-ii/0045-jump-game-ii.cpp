class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currMax = 0;
        int currEnd = 0;
        for (int ind=0; ind<nums.size()-1; ++ind) {
            currMax = max(currMax, ind + nums[ind]);
            if (ind == currEnd) {
                jumps++;
                currEnd = currMax;
            }
        }
        return jumps;
    }
};