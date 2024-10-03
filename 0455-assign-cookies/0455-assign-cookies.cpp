class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        if (s.size() == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childrenInd = 0;
        int cookieInd = 0;
        while (childrenInd < g.size() && cookieInd < s.size()) {
            if (g[childrenInd] <= s[cookieInd]) childrenInd++;
            cookieInd++;
        }
        return childrenInd;
    }
};