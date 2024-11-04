public class Solution {
    public int LongestConsecutive(int[] nums) {
        var sequence = new Dictionary<int, bool>();
        foreach (int x in nums) sequence[x] = true;
        foreach (int x in nums) {
            if (sequence.ContainsKey(x - 1)) sequence[x] = false;
        }
        int max_len = 0;
        foreach (var x in sequence.Keys) {
            if (!sequence[x]) continue;
            int len = 1;
            int current = x;
            while (sequence.ContainsKey(++current)) len++;
            max_len = Math.Max(max_len, len);
        }
        
        return max_len;
    }
}
