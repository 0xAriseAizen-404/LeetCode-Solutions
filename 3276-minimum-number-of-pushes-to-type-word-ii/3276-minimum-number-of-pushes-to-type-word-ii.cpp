class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char ch: word) ++freq[ch - 'a'];
        sort(freq.rbegin(), freq.rend());
        int cost = 0;
        for (int i = 0; i < 26 && freq[i]; i++) {
            cost += (freq[i] * (i / 8 + 1));
        }
        return cost;
    }
};
// TC: O(n) + O(26log26) + O(26) = O(n)
// SC: O(26) = O(1)

// class Solution {
// public:
//     int minimumPushes(string word) {
//         unordered_map<char, int> umap;
//         for (char c: word) umap[c]++;
//         priority_queue<pair<int, char>> pq;
//         for (auto &[ch, freq]: umap) pq.push({freq, ch});
//         int cnt = 0, pushes = 1, cost = 0;
//         while (!pq.empty()) {
//             cnt += 1;
//             if (cnt > 8) {
//                 cnt = 1;
//                 pushes += 1;
//             }
//             auto [freq, ch] = pq.top(); pq.pop();
//             cost += (pushes * freq);
//         }
//         return cost;
//     }
// };
// TC: O(n) + 26*O(log26) + 26*O(log26) = O(n)
// SC: O(26) + O(26) = O(1)



// class Solution {
// public:
//     int minimumPushes(string word) {
//         unordered_map<char, int> ump;
//         for (char c: word) ump[c]++;
//         auto cmp = [](const pair<char, int> &a, const pair<char, int> &b) {
//             return a.second < b.second;
//         };
//         priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
//         for (auto p: ump) pq.push(p);
//         int cnt = 0;
//         int pushes = 1;
//         int cost = 0;
//         while (!pq.empty()) {
//             cnt++;
//             if (cnt > 8) {
//                 cnt = 1;
//                 pushes += 1;
//             }
//             auto p = pq.top(); pq.pop();
//             cost += (pushes * p.second);
//         }
//         return cost;
//     }
// };