class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max_cnt = 0;
		int curr_cnt = 0;
		for(int i=0;i<nums.length;++i) {
			if(nums[i] == 1) curr_cnt++;
			else {
				max_cnt = Math.max(max_cnt, curr_cnt);
				curr_cnt = 0;
			}
		}
	    max_cnt = Math.max(max_cnt, curr_cnt);
		return max_cnt;
    }
}