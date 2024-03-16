class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> hMap = new HashMap<>();
        hMap.put(0, -1);
        int count = 0;
        int maxLen = 0;
        for(int i=0; i<nums.length; ++i) {
            count += nums[i]==1 ? 1 : -1;
            if(hMap.containsKey(count))
                maxLen = Math.max(maxLen, i - hMap.get(count));
            else
                hMap.put(count, i);
        }
        return maxLen;
    }
}