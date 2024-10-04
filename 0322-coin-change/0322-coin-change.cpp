class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> amt(amount + 1, amount + 1);
        amt[0] = 0;
        for (int val=1; val<=amount; ++val) {
            for (auto const &x: coins) {
                if (val >= x)
                    amt[val] = min(amt[val], 1 + amt[val - x]);
            }
        }
        return amt[amount] < amount + 1 ? amt[amount] : -1;
    }
};