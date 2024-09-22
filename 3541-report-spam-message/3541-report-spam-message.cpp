class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, bool> umap;
        for (auto &x: bannedWords) umap[x] = true;
        int count = 0;
        for (auto &x: message) {
            if (umap[x]) count++;
        }
        return count >= 2;
    }
};