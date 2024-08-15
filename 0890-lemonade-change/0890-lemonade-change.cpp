class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int fives = 0, tens = 0;
        for (const int &x: bills) {
            if (x == 5) fives++;
            else if (x == 10) {
                if (fives > 0) fives--, tens++;
                else return false;
            } else if (x == 20) {
                if (tens > 0 && fives > 0) tens--, fives--;
                else if (fives >= 3) fives -= 3;
                else return false;
            }
        }
        return true;
    }
};