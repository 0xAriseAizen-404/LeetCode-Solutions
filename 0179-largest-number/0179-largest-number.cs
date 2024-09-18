public class Solution {
    public string LargestNumber(int[] nums) {
        string[] strNums = new string[nums.Length];
        for (int i = 0; i < nums.Length; i++) 
            strNums[i] = nums[i].ToString();
        Array.Sort(strNums, (x, y) => (y + x).CompareTo(x + y));
        string res = string.Concat(strNums);
        return res[0] == '0' ? "0" : res;
    }
}
