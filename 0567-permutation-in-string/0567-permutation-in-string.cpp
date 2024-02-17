class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        vector<int> s1Map(26), s2Map(26);
        
        for (int i = 0; i < s1.size(); i++) {
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (s1Map == s2Map) {
                return true;
            }
            
            s2Map[s2[i] - 'a']--;
            s2Map[s2[i + s1.size()] - 'a']++;
        }
        
        return s1Map == s2Map;
    }
};
