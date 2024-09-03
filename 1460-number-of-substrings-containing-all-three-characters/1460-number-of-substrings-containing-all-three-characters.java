class Solution {
    private static boolean myHelper(int[] abc) {
        return (abc[0] > 0 && abc[1] > 0 && abc[2] > 0);
    }
    public int numberOfSubstrings(String s) {
        int count = 0;
        int left = 0;
        int right = 0;
        int[] abc = new int[3];
        Arrays.fill(abc, 0);
        while (right < s.length()) {
            abc[s.charAt(right) - 'a']++;
            while (myHelper(abc)) abc[s.charAt(left++) - 'a']--;
            count += left;
            right++;
        }
        return count;
    }
}