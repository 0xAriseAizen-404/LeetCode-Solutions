class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> ind(n), oud(n);
        for (vector<int>& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            string s;
            s += colors[u];
            s += colors[v];
            if (s[0] == s[1]) return -1;
            if (string("BWRB").find(s) != string::npos) {
                oud[u]++;
                ind[v]++;
            } else {
                ind[u]++;
                oud[v]++;
            }
        }
        if (*min_element(ind.begin(), ind.end()) > 0) return -1;
        if (*max_element(ind.begin(), ind.end()) > 1) return -1;
        if (*max_element(oud.begin(), oud.end()) > 2) return -1;
        if (count(ind.begin(), ind.end(), 0) > 1) return -1;
        return find(ind.begin(), ind.end(), 0) - ind.begin();
    }
};