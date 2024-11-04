public class Solution {
    public int Trap(int[] height) {
        int n = height.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i=1; i<n; ++i) left[i] = Math.Max(left[i - 1], height[i]);
        for (int i=n-2; i>=0; --i) right[i] = Math.Max(right[i + 1], height[i]);

        int area = 0;
        for (int i=0; i<n; ++i)
            area += Math.Min(left[i], right[i]) - height[i];
        return area;
    }
}