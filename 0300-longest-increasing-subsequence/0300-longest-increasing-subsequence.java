class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] lis = new int[n];
        Arrays.fill(lis, 1);
        int maxLen = 1;
        for (int i=1; i < n; ++i) {
            for (int j=0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = Math.max(lis[i], 1 + lis[j]);
                    maxLen = Math.max(maxLen, lis[i]);
                }
            }
        }
        return maxLen;
    }
}