class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;
        int count = 0;
        for (auto &x: words1) {
            freq1[x]++;
        }
        for (auto &x: words2) {
            freq2[x]++;
        }
        for (auto &x: freq1) {
            if (x.second == 1 && freq2[x.first] == 1) {
                count++;
            }
        }
        return count;
    }
};



// class Solution {
// public:
//     int countWords(vector<string>& words1, vector<string>& words2) {
//         unordered_map<string, int> umap;
//         int count = 0;
        
//         for (auto &x: words1) umap[x]++;
//         for (auto &x: words2) umap[x]--;

//         for (auto &x: umap) {
//             if (x.second == 0) count++;
//         }

//         return count;
//     }
// };