class Solution {
    public void reverseString(char[] s) {
        for(int i = 0, j = s.length - 1; i < j; i++, j--){
            s[j] = (char) (Integer.valueOf(s[i]) + Integer.valueOf(s[j]));
            s[i] = (char) (Integer.valueOf(s[j]) - Integer.valueOf(s[i]));
            s[j] = (char) (Integer.valueOf(s[j]) - Integer.valueOf(s[i]));
        }
        System.out.println(Arrays.toString(s));        
    }
}