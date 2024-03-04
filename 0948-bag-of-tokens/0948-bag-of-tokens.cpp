class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size() - 1;
        int currScore = 0;
        int maxScore = 0;
        while(left <= right) {
            if(tokens[left] <= power) {
                power -= tokens[left];
                currScore += 1;
                left += 1;
            } else {
                if(currScore >= 1) {
                    power += tokens[right];
                    currScore -= 1;
                }
                right -= 1;
            }
            maxScore = max(maxScore, currScore);
        }
        return maxScore;
    }
};