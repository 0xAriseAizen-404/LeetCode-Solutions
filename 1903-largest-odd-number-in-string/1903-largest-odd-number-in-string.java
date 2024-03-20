class Solution {
    public String largestOddNumber(String num) {
        int left = 0;
        int right = num.length() - 1;
        String oddNums = "13579";
        while(right >= 0) {
            if(oddNums.indexOf(num.charAt(right)) != -1)
                return num.substring(left, right + 1);
            right--;
        }
        return "";
    }
}