class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        unordered_map<char, int> umap;
        for (char& c: jewels) umap[c]++;
        int count = 0;
        for (char& c: stones) {
            if (umap[c] != 0)
                count++;
        }
        return count;
    }
};