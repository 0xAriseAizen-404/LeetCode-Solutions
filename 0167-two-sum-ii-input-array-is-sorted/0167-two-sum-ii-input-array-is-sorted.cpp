class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int summ = nums[low] + nums[high];
            if(summ == target) break;
            else if(summ > target) high--;
            else low++;
        }
        return {low+1, high+1};
    }
};