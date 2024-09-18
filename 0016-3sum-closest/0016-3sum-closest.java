import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int val = nums[i] + nums[left] + nums[right];
                if (Math.abs(val - target) < Math.abs(closestSum - target)) {
                    closestSum = val;
                }
                if (val < target) {
                    left++;
                } else if (val > target) {
                    right--;
                } else {
                    return val;
                }
            }
        }
        return closestSum;
    }
}
