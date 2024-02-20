class Solution {
    public int missingNumber(int[] nums) {
        int org_xor = 0;
        int given_xor = 0;
        for(int i=1;i<=nums.length;++i)
            org_xor ^= i;
        for(int x : nums)
            given_xor ^= x;
        return org_xor^given_xor;
        
        // int org_sum = (nums.length*(nums.length + 1)) / 2;
        // int summ = Arrays.stream(nums).sum();
        // return org_sum - summ;
    }
}