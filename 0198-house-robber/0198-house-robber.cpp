class Solution {
public:
    int rob(vector<int>& nums) {
        int robHouse0 = 0;
        int robHouse1 = 0;
        int maxRobbed = 0;
        for (int i=0; i<nums.size(); ++i) {
            maxRobbed = max((robHouse0 + nums[i]), robHouse1);
            robHouse0 = robHouse1;
            robHouse1 = maxRobbed;
        }
        return maxRobbed;
    }
};