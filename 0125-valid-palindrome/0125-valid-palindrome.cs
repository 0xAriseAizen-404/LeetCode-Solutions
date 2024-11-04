public class Solution {
    private static bool IsAlphanumeric(char x) {
        return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
    }
    public bool IsPalindrome(string s) {
        int left = 0;
        int right = s.Length - 1;

        while (left < right) {
            while (left < right && !IsAlphanumeric(s[left])) left++;
            while (left < right && !IsAlphanumeric(s[right])) right--;
            if (char.ToLower(s[left++]) != char.ToLower(s[right--])) return false;
        }
        return true;
    }
}
