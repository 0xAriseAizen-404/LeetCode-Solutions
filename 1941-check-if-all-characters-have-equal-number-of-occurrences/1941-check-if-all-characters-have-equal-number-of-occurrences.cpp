class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> u_map;
        for(char x: s)
            u_map[x]++;
        int same = u_map[s[0]];
        for(auto& p: u_map) {
            if(p.second != same)
                return 0;
        }
        return 1;
    }
};