public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        var N = nums.Length;
        var output = new int[nums.Length];
        output[0] = 1;
        for(var i = 1; i < N; i++)
        {
            output[i] = nums[i -1] * output[i-1];
        }
        int R = 1;
        for(var i = N - 1; i >= 0; i--)
        {
            output[i] = output[i] * R;
            R = R * nums[i];
        }
        return output;
    }
}