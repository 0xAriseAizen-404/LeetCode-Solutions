class Solution {
    public String largestOddNumber(String num) {
        int left = 0;
        int right = num.length() - 1;
        while(right >= 0) {
            if(num.charAt(right)%2 == 1)
                return num.substring(left, right + 1);
            right--;
        }
        return "";
    }
}