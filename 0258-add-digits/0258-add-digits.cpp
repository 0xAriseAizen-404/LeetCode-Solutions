class Solution {
public:
    int addDigits(int n) {
        int num = n;
        while(num > 9) {
            int summ = 0;
            while(num != 0) {
                summ += num%10;
                num /= 10;
            }
            num = summ;
        }
        return num;
    }
};