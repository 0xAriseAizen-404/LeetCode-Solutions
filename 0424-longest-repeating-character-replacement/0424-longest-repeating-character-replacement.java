class Solution {
    public int characterReplacement(String s, int k) {
        HashMap<Character, Integer> hMap = new HashMap<>();
        int left = 0;
        int right = 0;
        int maxx = Integer.MIN_VALUE;
        int length = 0;
        for(right=0;right<s.length();++right) {
            hMap.put(s.charAt(right), hMap.getOrDefault(s.charAt(right), 0) + 1);
            maxx = Math.max(maxx, hMap.get(s.charAt(right)));
            if((right - left + 1 - maxx) <= k) {
                // len of substring - maxx freq = min. changes of char
                length = Math.max(length, right - left + 1);
            } else {
                hMap.put(s.charAt(left), hMap.get(s.charAt(left))-1);
                left++;
            }
        }
        return length;
    }
}