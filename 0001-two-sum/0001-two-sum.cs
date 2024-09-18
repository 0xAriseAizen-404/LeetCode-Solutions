public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        for (int i=0; i<nums.Length; ++i) {
            if (dict.ContainsKey(target - nums[i])) return new int[2]{dict[target-nums[i]], i};
            dict[nums[i]] = i;
        }
        return new int[2]{-1, -1};
    }
}