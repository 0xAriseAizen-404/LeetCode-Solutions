class Solution {
    private int getMaxElement(int[] arr) {
        int maxElement = Integer.MIN_VALUE;
        for (int x : arr) {
            maxElement = Math.max(maxElement, x);
        }
        return maxElement;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = getMaxElement(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            double totalHours = 0;

            for (int x : piles) {
                totalHours += Math.ceil((double) x / (double)mid);
            }

            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}
