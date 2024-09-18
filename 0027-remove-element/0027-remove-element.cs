public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int n = nums.Length;
        if (n == 0) return 0;
        int k = -1;
        for (int i=0; i<n; ++i) {
            if (nums[i] == val) {
                k = i;
                break;
            }
        }
        if (k == -1) return n;
        for (int i=k+1; i<n; ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                nums[i] = val;
                k++;
            }
        }
        return k;
    }
}