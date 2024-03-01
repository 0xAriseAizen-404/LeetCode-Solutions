class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count_ones = 0;
        int count_zeros = 0;
        for(char x : s) {
            if (x == '1') {
                count_ones++;
            } else {
                count_zeros++;
            }
        }
        std::string result;
        for(int i=0; i<count_ones-1; ++i) result += '1';
        for(int i=0; i<count_zeros; ++i) result += '0';
        result += '1';
        return result;
    }
};