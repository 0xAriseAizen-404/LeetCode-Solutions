class Solution {
    public int singleNonDuplicate(int[] nums) {
        // int xor = 0;
        // for(int x : nums) xor ^= x;
        // return xor;
        
        if(nums.length == 1) return nums[0];
        int low = 1;
        int high = nums.length - 2;
        if(nums[low] != nums[low - 1]) return nums[low - 1];
        if(nums[high] != nums[high + 1]) return nums[high + 1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid - 1] == nums[mid]) {
                if((mid & 1) == 1) low = mid + 1;
                else high = mid - 1;
            } else if(nums[mid] == nums[mid + 1]) {
                if((mid & 1) == 1) high = mid - 1;
                else low = mid + 1;
            } else return nums[mid];
        }
        return -1;
    }
}