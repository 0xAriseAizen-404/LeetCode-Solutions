public class Solution {
    public int MaxProfit(int[] prices) {
        int maxProfit = int.MinValue;
        int minValue = prices[0];
        foreach (int x in prices) {
            maxProfit = Math.Max(maxProfit, (x - minValue));
            minValue = Math.Min(minValue, x);
        }
        return maxProfit;
    }
}