class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) {
            return 0; // Since the product will always be greater than or equal to 1 if k is 1 or less.
        }

        int cnt = 0;
        int product = 1;
        int left = 0;

        for (int right = 0; right < nums.length; right++) {
            product *= nums[right];

            // Shrink the window from the left until the product is less than k.
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // Each subarray [left, right] with product less than k is valid.
            cnt += (right - left + 1);
        }

        return cnt;
    }
}
