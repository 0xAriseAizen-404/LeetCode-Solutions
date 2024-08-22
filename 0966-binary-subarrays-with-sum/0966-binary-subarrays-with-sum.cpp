class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return myHelper(nums, goal) - myHelper(nums, goal - 1);
    }
    int myHelper(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0;
        int right = 0;
        int summ = 0;
        int count = 0;
        while (right < nums.size()) {
            summ += nums[right];
            while (summ > goal) summ -= nums[left++];
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};