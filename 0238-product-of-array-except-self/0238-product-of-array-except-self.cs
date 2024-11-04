public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        var list = new List<int> ();
        int pre = 1;
        foreach (int x in nums) {
            list.Add(pre);
            pre *= x;
        }

        int post = 1;
        for (int i=nums.Length - 1; i >= 0; --i) {
            list[i] *= post;
            post *= nums[i];
        }
        return list.ToArray();
    }
}