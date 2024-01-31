class Solution {
    public String reverseOnlyLetters(String s) 
    {
        int left=0;
        int right = s.length()-1;
        int n = s.length();
        StringBuilder str = new StringBuilder(s);
        while(left<right)
        {
            if(!Character.isLetter(s.charAt(left))) left++;
            if(!Character.isLetter(s.charAt(right))) right--;
            if(Character.isLetter(s.charAt(left)) && Character.isLetter(s.charAt(right))) {
                // s = s.substring(0, left) + s.charAt(right) + s.substring(left + 1);
                // s = s.substring(0, right) + s.charAt(left) + s.substring(right + 1);
                str.setCharAt(left, s.charAt(right));
                str.setCharAt(right, s.charAt(left));
                left++;
                right--;
            }
        }
        return str.toString();
    }
}