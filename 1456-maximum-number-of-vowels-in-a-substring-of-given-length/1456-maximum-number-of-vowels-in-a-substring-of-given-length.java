class Solution {
    
    public boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public int maxVowels(String s, int k) {
        int windowStart = 0;
        int maxCount = 0;
        int count = 0;

        for (int windowEnd = 0; windowEnd < s.length(); ++windowEnd) {
            if (isVowel(Character.toLowerCase(s.charAt(windowEnd)))) {
                count++;
            }

            if (windowEnd >= k - 1) {
                maxCount = Math.max(maxCount, count);
                if (isVowel(Character.toLowerCase(s.charAt(windowStart)))) {
                    count--;
                }
                windowStart++;
            }
        }

        return maxCount;
    }
};