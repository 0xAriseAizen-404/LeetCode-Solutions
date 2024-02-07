class Solution{
    public int longestConsecutive(int[] nums) {
        int maxLength = 0;
        HashMap<Integer, Boolean> map = new HashMap<>();
        for(int val : nums)
            map.put(val, true);
        
        for(int val : nums) 
            if(map.containsKey(val - 1))
                map.put(val, false);
        
        for(int val : nums) {
            if(map.get(val)) {
                int length = 1, start = val+1;
                
                while(map.containsKey(start))
                    start++;
                
                if((start-val)  > maxLength)
                    maxLength = start-val;
            }
        }
        
        return maxLength;     
    }
}