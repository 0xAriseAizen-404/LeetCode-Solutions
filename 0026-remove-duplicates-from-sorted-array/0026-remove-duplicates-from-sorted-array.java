class Solution {
    public int removeDuplicates(int[] nums) {
        int left = 0;
        for (int right=1; right<nums.length; ++right) {
            if (nums[left] != nums[right]) {
                int temp = nums[right];
                nums[right] = nums[left+1];
                nums[++left] = temp;
            }
        }
        return left+1;
    }
}