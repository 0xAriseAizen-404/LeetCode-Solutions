class Solution {
public:
    int minOperations(vector<string>& logs) {
        int distance = 0;
        for (string x: logs) {
            if (x == "./") continue;
            else if (x == "../") {
                if (distance > 0) distance--;
            }
            else distance++;
        }
        return distance;
    }
};