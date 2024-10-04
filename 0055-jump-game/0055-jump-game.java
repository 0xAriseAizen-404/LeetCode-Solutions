class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int goal = n - 1;
        for (int ind = goal - 1; ind >= 0; ind--) {
            if ((ind + nums[ind]) >= goal) goal = ind;
        }
        return goal == 0;

        // int n = nums.length;
        // boolean[] dp = new boolean[n];
        // dp[n - 1] = true;
        // for (int i = n - 2; i >= 0; --i) {
        //     int maxJump = Math.min(i + nums[i], n - 1);
        //     for (int j = i + 1; j <= maxJump; ++j) {
        //         if (dp[j]) {
        //             dp[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return dp[0];
    }
}
