class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> umap;
        vector<string> res;

        // Helper function to split string by spaces and update the map
        auto processSentence = [&](string &s) {
            int start = 0;
            int end = 0;
            while ((end = s.find(' ', start)) != string::npos) {
                umap[s.substr(start, end - start)]++;
                start = end + 1;
            }
            umap[s.substr(start)]++; // last word
        };

        processSentence(s1);
        processSentence(s2);

        for (auto &x : umap) {
            if (x.second == 1) res.push_back(x.first);
        }

        return res;
    }
};
