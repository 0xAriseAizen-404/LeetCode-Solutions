public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        int closest_sum = int.MaxValue;

        for (int i = 0; i < nums.Length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.Length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (Math.Abs(sum - target) < Math.Abs(closest_sum - target)) {
                    closest_sum = sum;
                }
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return sum;
                }
            }
        }

        return closest_sum;
    }
}
