public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int[] hash = new int[256];
        for (int i=0; i<256; ++i) hash[i] = -1;
        int left = 0;
        int right = 0;
        int max_len = 0;
        while (right < s.Length) {
            int ind = (int)s[right];
            if (hash[ind] == -1 || hash[ind] < left) hash[ind] = right;
            else {
                left = hash[ind] + 1;
                hash[ind] = right;
            }
            max_len = Math.Max(max_len, (right - left + 1));
            right++;
        }
        return max_len;
    }
}