class Solution {
public:
    int reverse(int x) {
        int reverseNumber = 0;
        while (x != 0) {
            int remainder = x % 10;
            if ((reverseNumber > INT_MAX / 10) || ((reverseNumber == INT_MAX / 10) && (remainder > 7)))
                return 0;
            if ((reverseNumber < INT_MIN / 10) || ((reverseNumber == INT_MIN / 10) && (remainder < -8)))
                return 0;
            reverseNumber = reverseNumber * 10 + remainder;
            x = x / 10;
        }
        return reverseNumber;
    }
};