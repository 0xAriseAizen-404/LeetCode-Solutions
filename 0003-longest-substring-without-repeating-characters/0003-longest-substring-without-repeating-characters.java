class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        StringBuilder sb = new StringBuilder();

        while (right < s.length()) {
            if (sb.indexOf(s.substring(right, right + 1)) != -1) {
                max_len = Math.max(max_len, sb.length());
                sb.delete(0, sb.indexOf(s.substring(right, right + 1)) + 1);
            }
            sb.append(s.charAt(right));
            right++;
        }

        // Check for the last substring
        max_len = Math.max(max_len, sb.length());

        return max_len;
    }
}
