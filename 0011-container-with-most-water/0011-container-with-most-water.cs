public class Solution {
    public int MaxArea(int[] height) {
        int max_area = int.MinValue;
        int left = 0;
        int right = height.Length - 1;

        while (left < right) {
            int curr_area = (right - left) * Math.Min(height[left], height[right]);
            max_area = Math.Max(max_area, curr_area);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }
}