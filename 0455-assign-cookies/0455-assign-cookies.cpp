class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
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