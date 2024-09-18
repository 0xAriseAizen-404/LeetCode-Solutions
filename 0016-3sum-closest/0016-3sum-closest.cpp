class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int val = nums[i] + nums[left] + nums[right];
                if (abs(val - target) < abs(closest_sum - target)) closest_sum = val;
                if (val < target) left++; 
                else if (val > target) right--;
                else return val; 
            }
        }
        return closest_sum;
    }
};
