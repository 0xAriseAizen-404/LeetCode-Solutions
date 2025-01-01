class Solution {
private:
    int findOneCount(string s) {
        // return count(s.begin(), s.end(), '1');

        int cnt = 0;
        for (char x: s) cnt += (x == '1') ? 1 : 0;
        return cnt;
    }
public:
    int maxScore(string s) {
        int zerosCount = 0;
        int onesCount = findOneCount(s);
        int maxCount = 0;
        for (int i=0; i<s.length()-1; i++) {
            zerosCount += (s[i] == '0') ? 1 : 0;
            onesCount -= (s[i] == '1') ? 1 : 0;
            maxCount = max(maxCount, zerosCount + onesCount);
        }
        return maxCount;
    }
};