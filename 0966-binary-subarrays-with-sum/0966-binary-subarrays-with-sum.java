class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        return myHelper(nums, goal) - myHelper(nums, goal - 1);
    }
    private static int myHelper(int[] nums, int goal) {
        if (goal < 0) return 0;
        int summ = 0;
        int count = 0;
        int left = 0;
        for (int right = 0; right < nums.length; ++right) {
            summ += nums[right];
            while (summ > goal) summ -= nums[left++];
            count += (right - left + 1);
        }
        return count;
    }
}