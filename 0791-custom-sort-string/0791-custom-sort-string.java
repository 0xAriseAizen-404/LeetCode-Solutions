class Solution {
public:
    string customSortString(string order, string s) {
        string res = "";
        unordered_map<int, int> umap;
        for(auto& it: s)
            umap[it]++;
        for(auto& it: order) {
            if(umap.find(it) != umap.end()) {
                res.append(umap[it], it);
                umap.erase(it);
            }
        }
        for(auto& it: umap)
            // append(times, value);
            res.append(it.second, it.first);
        return res;
    }
};