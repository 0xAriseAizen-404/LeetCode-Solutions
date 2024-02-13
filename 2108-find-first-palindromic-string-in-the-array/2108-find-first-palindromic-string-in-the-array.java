class Solution {
    public String firstPalindrome(String[] words) {
        for(String str : words) {
            StringBuilder sb = new StringBuilder(str).reverse();
            if(str.equals(sb.toString())) return str;
        }
        return new String("");
    }
}