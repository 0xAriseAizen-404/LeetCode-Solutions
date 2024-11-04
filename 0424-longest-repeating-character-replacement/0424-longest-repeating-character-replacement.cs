public class Solution {
    public int CharacterReplacement(string s, int k) {
        int[] freq = new int[26];
        int left = 0, right = 0;
        int maxLength = int.MinValue;
        int maxFreq = -1;
        while (right < s.Length) {
            maxFreq = Math.Max(maxFreq, ++freq[s[right] - 'A']);
            if ((right - left + 1) - maxFreq > k) --freq[s[left++] - 'A'];
            maxLength = Math.Max(maxLength, (right - left + 1));
            right++;
        }
        return maxLength;
    }
}