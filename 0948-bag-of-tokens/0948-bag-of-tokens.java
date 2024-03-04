class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int left = 0;
        int right = tokens.length - 1;
        int currScore = 0;
        int maxScore = 0;
        
        while (left <= right) {
            if (tokens[left] <= power) {
                power -= tokens[left];
                currScore++;
                left++;
            } else {
                if (currScore >= 1) {
                    power += tokens[right];
                    currScore--;
                }
                right--;
            }
            maxScore = Math.max(maxScore, currScore);
        }
        
        return maxScore;
    }
}
