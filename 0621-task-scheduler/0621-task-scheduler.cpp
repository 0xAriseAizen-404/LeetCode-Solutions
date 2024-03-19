class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        unordered_map<char, int> map;
        int maxFreq = 0;
        int noOfMaxFreq = 0;
        for(char c: tasks) {
            map[c]++;
            maxFreq = max(maxFreq, map[c]);
        }
        for(pair<int, int> x: map)
            if(x.second == maxFreq)
                noOfMaxFreq++;
        int res = max(((n+1)*(maxFreq-1)+noOfMaxFreq), len);
        return res;
    }
};