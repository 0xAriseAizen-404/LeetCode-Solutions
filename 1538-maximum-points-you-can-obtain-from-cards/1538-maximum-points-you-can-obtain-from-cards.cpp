class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int sz = cardPoints.size();
        int leftSum = 0;
        for (int i=0; i<k; ++i) leftSum += cardPoints[i];
        int maxSum = leftSum;
        if (k == cardPoints.size()) return leftSum;
        int rightSum = 0;
        for (int i=1; i<=k; ++i) {
            leftSum -= cardPoints[k-i];
            rightSum += cardPoints[sz-i];
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};