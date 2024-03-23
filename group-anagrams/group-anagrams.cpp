class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (string& x : strs) {
            string origin = x;
            sort(x.begin(), x.end());
            umap[x].emplace_back(origin);
        }
        vector<vector<string>> result;
        for (auto& entry : umap) {
            result.push_back(entry.second);
        }
        return result;
    }
};
