class Solution {
    public int singleNumber(int[] nums) {
        // int xor = 0;
        // for(int x : nums) xor ^= x;
        // return xor;
        
        // Better Solution using HashSet
        Set<Integer> mySet = new HashSet<>();
        for(int x: nums) {
            if (mySet.contains(x))
                mySet.remove(x);
            else
                mySet.add(x);
        }
        int ans = 0;
        for(Integer i: mySet)
            ans = i;
        return ans;
    }
}