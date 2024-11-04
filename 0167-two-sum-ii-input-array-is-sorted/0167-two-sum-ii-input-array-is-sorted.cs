public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int idx_low = 0;
        int idx_high = nums.Length - 1;
        while((nums[idx_low] + nums[idx_high]) != target) {
            if(nums[idx_low] + nums[idx_high] > target) --idx_high;
            else ++idx_low;
        }
        return new int[] {idx_low + 1, idx_high + 1};
    }
}