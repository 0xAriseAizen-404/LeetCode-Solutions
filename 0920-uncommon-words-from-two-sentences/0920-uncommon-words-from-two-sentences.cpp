class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> umap;

        stringstream ss1(s1), ss2(s2);
        string word;

        while (ss1 >> word) {
            umap[word]++;
        }

        while (ss2 >> word) {
            umap[word]++;
        }

        for (auto &x: umap) {
            if (x.second == 1) {
                res.push_back(x.first);
            }
        }

        return res;
    }
};
