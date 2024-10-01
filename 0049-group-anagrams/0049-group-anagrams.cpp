class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<int> hash;
        for (const auto &str: strs) {
            hash.assign(26, 0);
            for (const auto &x: str) {
                hash[tolower(x) - 'a']++;
            }
            string encode = "";
            for (const auto &x: hash) encode += x;
            umap[encode].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto &x: umap) res.push_back(x.second);
        return res;
    }
};