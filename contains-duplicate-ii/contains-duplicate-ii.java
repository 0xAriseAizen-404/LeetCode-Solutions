class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> umap = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (umap.containsKey(nums[i]) && Math.abs(umap.get(nums[i]) - i) <= k) {
                return true;
            }
            umap.put(nums[i], i);
        }
        return false;
    }
}
