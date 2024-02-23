class Solution {
    private int getMinEle(int[] arr) {
        int minEle = Integer.MAX_VALUE;
        for(int x : arr) {
            minEle = Math.min(minEle, x);
        }
        return minEle;
    }
    private int getMaxEle(int[] arr) {
        int maxEle = Integer.MIN_VALUE;
        for(int x : arr) {
            maxEle = Math.max(maxEle, x);
        }
        return maxEle;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        if(bloomDay.length < m*k) return -1;
        int low = getMinEle(bloomDay);
        int high = getMaxEle(bloomDay);
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int count  = 0;
            int tracker = 0;
            for(int x : bloomDay) {
                if(x <= mid) tracker++;
                else {
                    count += tracker/k;
                    tracker = 0;
                }
            }
            count += tracker / k;
            if(count >= m) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        // return (low != (getMaxEle(bloomDay)+1)) ? low : -1;
        return ans;
    }
}