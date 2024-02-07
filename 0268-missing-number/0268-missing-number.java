class Solution {
    public int missingNumber(int[] nums) {
        int org_xor = 0;
        int given_xor = 0;
        for(int i=1;i<=nums.length;++i)
            org_xor ^= i;
        for(int x : nums)
            given_xor ^= x;
        return org_xor^given_xor;
    }
}