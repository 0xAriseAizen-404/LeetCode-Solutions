class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (char x : t) 
            map[x]++;
        
        int matched = 0;
        int startInd = 0;
        int subStrStartInd = 0;
        int minLen = s.size() + 1;
        
        for (int endInd = 0; endInd < s.size(); endInd++) {
            char x = s[endInd];
            if (map.find(x) != map.end()) {
                map[x]--;
                if (map[x] == 0)
                    matched += 1;
            }
            
            while (matched == map.size()) {
                if (minLen > (endInd - startInd + 1)) {
                    minLen = endInd - startInd + 1;
                    subStrStartInd = startInd;
                }
                
                char deleted = s[startInd];
                if (map.find(deleted) != map.end()) {
                    if (map[deleted] == 0) 
                        matched--;
                    map[deleted]++;
                }
                
                startInd++;
            }
        }
        
        return minLen > s.size() ? "" : s.substr(subStrStartInd, minLen);
    }
};
