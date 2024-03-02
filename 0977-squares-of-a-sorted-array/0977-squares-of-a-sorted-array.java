class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] ans = new int[nums.length];
        int ind = ans.length - 1;
        
        int left = 0;
        int right = nums.length - 1;
        while(left <= right) {
            if(Math.pow(nums[left], 2) > Math.pow(nums[right], 2))
                ans[ind--] = (int)Math.pow(nums[left++], 2);
            else
                ans[ind--] = (int)Math.pow(nums[right--], 2);
        }
        return ans;
    }
}