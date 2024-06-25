class Solution {
public:
    bool isPalindrome(int A) {
        if (A < 0)
        return 0;
        int num_digits = 0;
        int temp = A;
        while (temp > 0) {
            num_digits += 1;
            temp /= 10;
        }
        temp = A;
        while (temp > 0) {
            int left_digit = temp / int(pow(10, num_digits - 1));
            int right_digit = temp % 10;
            if (left_digit != right_digit)
                return 0;
            // remove left and right digits
            temp = (temp % int(pow(10, num_digits - 1))) / 10;
            num_digits -= 2;
        }
        return 1;
    }
};