public class Solution {
    public static int checkPalidrome(string s, int left, int right) {
        while (left>=0 && right<s.Length && s[left] == s[right]) {
            left--; right++;
        }
        return right - left - 1;
    }
    public string LongestPalindrome(string s) {
        if (s == "") return "";
        int start = 0;
        int end = 0;
        for (int ind = 0; ind < s.Length; ind++) {
            int odd_len = checkPalidrome(s, ind, ind);
            int even_len = checkPalidrome(s, ind, ind + 1);
            int len = odd_len > even_len ? odd_len : even_len;
            if (len > end - start) {
                start = ind - (len - 1) / 2;
                end = ind + len / 2;
            }
        }
        return s.Substring(start, end - start + 1);
    }
}