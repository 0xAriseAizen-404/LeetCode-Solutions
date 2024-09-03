class Solution {
public:
    bool check(vector<int> &v1,vector<int> &v2){
        for(int i = 0; i < 26; i++){
            if(v1[i]<v2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26,0),v2(26,0);
        for(auto &i: s1){
            v1[i-'a']++;
        }
        int i = 0, j = 0, n = s2.length();
        while(j<n){
            v2[s2[j]-'a']++;
            if(j<s1.length()-1){
                j++;
            }else{
                if(check(v1,v2)){
                    return true;
                }
                v2[s2[i++]-'a']--;
                j++;
            }
        }
        return false;
    }
};