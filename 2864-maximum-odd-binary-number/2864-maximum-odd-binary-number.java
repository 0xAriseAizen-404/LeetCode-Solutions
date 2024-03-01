class Solution {
    public String maximumOddBinaryNumber(String s) {
        int count_ones = 0; //(int)s.chars().filter(c => c == ch).count(); ch=='1'
        int count_zeros = 0; //(int)s.chars().filter(c => c == ch).count(); ch=='0'
        for(char x : s.toCharArray()) {
            if (x == '1') {
                count_ones++;
            } else {
                count_zeros++;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<count_ones-1; ++i) sb.append('1');
        for(int i=0; i<count_zeros; ++i) sb.append('0');
        sb.append('1');
        return sb.toString();
    }
}