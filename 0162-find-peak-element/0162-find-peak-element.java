class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        if(nums.length == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])  return mid;
            else if(nums[mid-1] < nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
        
        // if(nums.length == 1) return 0; 
        // int low = 0;
        // int high = nums.length - 1;
        // while(low < high){
        //     int mid = low + (high - low) / 2;
        //     if(nums[mid] < nums[mid+1]) low = mid + 1;
        //     else high = mid;
        // }
        // return low;
    }
}
