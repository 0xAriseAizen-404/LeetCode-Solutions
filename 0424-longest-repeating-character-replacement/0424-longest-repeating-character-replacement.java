class Solution {
    public int characterReplacement(String s, int k) {
        int[] chars = new int[26];
        
        int left = 0, right = 0;
        int maxLength = 0;
        int maxxFreq = 0;

        while (right < s.length()) {
            maxxFreq = Math.max(maxxFreq, ++chars[s.charAt(right) - 'A']);
            if ((right-left+1) - maxxFreq > k) {
                chars[s.charAt(left) - 'A']--;
                left++;
            }
            maxLength = Math.max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
}
