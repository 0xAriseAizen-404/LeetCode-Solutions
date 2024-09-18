public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int ind = 0;
        for (int i=0; i<nums.Length - 1; ++i) {
            if (nums[i] != nums[i+1]) nums[ind++] = nums[i];
        }
        nums[ind++] = nums[nums.Length - 1];
        return ind;
    }
}