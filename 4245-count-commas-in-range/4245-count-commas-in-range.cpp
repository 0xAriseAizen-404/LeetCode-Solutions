class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;
        else if (1000 <= n &&  n <= 100000) return 1 * (n - 999);
        else return -1;
    }
};