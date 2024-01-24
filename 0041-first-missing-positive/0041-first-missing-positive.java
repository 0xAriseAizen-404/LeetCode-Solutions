class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Boolean> hMap = new HashMap<>();
        for (int ele : nums) hMap.put(ele, true);
        for (int i = 1; i <= n; ++i) {
            if (!hMap.containsKey(i)) // Corrected method name
                return i;
        }
        return n + 1;
    }
}