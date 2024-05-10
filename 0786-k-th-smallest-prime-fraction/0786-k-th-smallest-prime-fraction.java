class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int n = arr.length;
        double left = 0.0, right = 1.0;
        int[] ans = new int[2];
        
        while (left < right) {
            double mid = left + (right - left) / 2;
            int count = 0;
            double maxFraction = 0.0;
            ans[0] = 0;
            ans[1] = 0;
            
            for (int i = 0, j = 0; i < n - 1; i++) {
                while (j < n && arr[i] > mid * arr[j]) {
                    j++;
                }
                count += n - j;
                if (j < n && maxFraction < (double) arr[i] / arr[j]) {
                    maxFraction = (double) arr[i] / arr[j];
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                }
            }
            
            if (count == k) {
                return ans;
            } else if (count < k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return ans;
    }
}