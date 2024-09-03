// own logic

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);

        int n = cardPoints.size();
        int *beginPresum = new int[k+1]();
        int *endPresum = new int[k+1]();
        for (int i=0; i<k; ++i) {
            beginPresum[i+1] = beginPresum[i] + cardPoints[i];
            endPresum[i+1] = endPresum[i] + cardPoints[n-i-1];
        }
        // for (int i=0; i<k+1; ++i) cout << beginPresum[i] << " " << endPresum[i] << endl;
        int max_score = INT_MIN;
        for (int i=0; i<k+1; ++i) max_score = max(max_score, (beginPresum[i] + endPresum[k-i]));
        return max_score;
    }
};