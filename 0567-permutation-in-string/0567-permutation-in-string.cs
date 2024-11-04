public class Solution {
    private static bool check(int[] freq1, int[] freq2) {
        for (int i=0; i<26; ++i)
            if (freq1[i] < freq2[i]) return false;
        return true;
    }
    public bool CheckInclusion(string s1, string s2) {
        int[] freq1 = new int[26];
        foreach (char x in s1) freq1[x - 'a']++;
        int[] freq2 = new int[26];
        int left = 0, right = 0;
        while (right < s2.Length) {
            freq2[s2[right] - 'a']++;
            if (right >= s1.Length - 1) {
                if (check(freq1, freq2)) return true;
                freq2[s2[left++] - 'a']--;
            }
            right++;
        }
        return false;
    }
}