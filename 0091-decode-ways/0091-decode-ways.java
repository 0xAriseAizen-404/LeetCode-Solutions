class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0 || s.charAt(0) == '0') return 0;
        if (s.length() == 1) return 1;
        int prevDecode2 = 1;
        int prevDecode1 = 1;
        for (int i=1; i<s.length(); ++i) {
            int currDecode = 0;
            if (s.charAt(i) != '0') currDecode += prevDecode1;
            int lastTwoDigits = Integer.parseInt(s.substring(i-1, i+1));
            if (10 <= lastTwoDigits && lastTwoDigits <= 26) 
                currDecode += prevDecode2;
            prevDecode2 = prevDecode1;
            prevDecode1 = currDecode;
        }
        return prevDecode1;
    }
}