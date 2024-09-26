class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        int ind = goal - 1;
        while (ind >= 0) {
            if (ind + nums[ind] >= goal) 
                goal = ind;
            ind--;
        }
        return goal == 0;
    }
};