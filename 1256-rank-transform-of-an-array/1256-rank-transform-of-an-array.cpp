class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &x: arr) pq.push(x);
        unordered_map<int, int> umap;
        int rank = 1;
        while (!pq.empty()) {
            if (umap.find(pq.top()) == umap.end()) {
                umap[pq.top()] = rank++;
            }
            pq.pop();
        }
        vector<int> res(arr.size(), 1);
        for (int i=0; i<arr.size(); ++i) {
            res[i] = umap[arr[i]];
        }
        return res;
    }
};