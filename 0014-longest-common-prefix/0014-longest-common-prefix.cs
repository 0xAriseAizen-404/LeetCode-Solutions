public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        
        Array.Sort(strs);
        int ind = 0;
        string res = "";
        int len = Math.Min(strs[0].Length, strs[strs.Length-1].Length);
        while (ind < len && strs[0][ind] == strs[strs.Length-1][ind]) res += strs[0][ind++];
        return res;
    }
}