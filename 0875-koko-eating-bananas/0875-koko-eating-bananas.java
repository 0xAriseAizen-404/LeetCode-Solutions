class Solution {
    int getMaxEle(int[] arr) {
        int maxEle = Integer.MIN_VALUE;
        for(int x : arr) {
            maxEle = Math.max(maxEle, x);
        }
        return maxEle;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = getMaxEle(piles);
        while(low < high) {
            int mid = low + (high - low) / 2;
            int totalHours = 0;
            for(int x : piles) {
                totalHours += Math.ceil(x / (double)mid);
            }
            if(totalHours <= h) high = mid;
            else low = mid + 1;
        }
        return high;
    }
}