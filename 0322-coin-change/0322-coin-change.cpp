class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // (amount + 1) - as value is an invalid or impossible case look for return statement to understand why (amount + 1) used;
        vector<int> amt(amount + 1, amount + 1);
        amt[0] = 0;
        for (int val=1; val<=amount; ++val) {
            for (auto const &x: coins) {
                if (x <= val)
                    amt[val] = min(amt[val], 1 + amt[val - x]);
                    // here 1 + amt[...] represents already naa dhaggara oka coin undhi val kante thakkuva so idhi nen theesukunna one quantity inka naku yentha kaavali (val - x) in tabulation => 1 + amt[val - x];
            }
        }
        return amt[amount] < amount + 1 ? amt[amount] : -1;
    }
};