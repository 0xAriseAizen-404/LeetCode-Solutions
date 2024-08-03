class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX;
        int maxPro = INT_MIN;
        for (auto x: prices) {
            minVal = min(minVal, x);
            maxPro = max(maxPro, (x - minVal));
        }
        return maxPro;
    }
};