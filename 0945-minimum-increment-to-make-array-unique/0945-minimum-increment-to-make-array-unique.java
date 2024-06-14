class Solution {
    public int minIncrementForUnique(int[] nums) {
        // HashMap<Integer, Boolean> hMap = new HashMap<Integer, Boolean>();
        // int i = 0;
        // int count = 0;
        // while(i < nums.length) {
        //     if (hMap.containsKey(nums[i])) {
        //         nums[i]++;
        //         count++;
        //         continue;
        //     } else {
        //         hMap.put(nums[i], true);
        //         i++;
        //     }
        // }
        // return count;
        
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
}