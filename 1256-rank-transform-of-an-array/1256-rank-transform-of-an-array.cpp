class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> umap;
        int rank = 1;
        for (const auto &x : sortedArr) {
            if (umap.find(x) == umap.end()) {
                umap[x] = rank++;
            }
        }
        vector<int> res(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            res[i] = umap[arr[i]];
        }
        return res;

        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (const auto &x: arr) pq.push(x);
        // unordered_map<int, int> umap;
        // int rank = 1;
        // while (!pq.empty()) {
        //     if (umap.find(pq.top()) == umap.end()) {
        //         umap[pq.top()] = rank++;
        //     }
        //     pq.pop();
        // }
        // vector<int> res(arr.size(), 1);
        // for (int i=0; i<arr.size(); ++i) {
        //     res[i] = umap[arr[i]];
        // }
        // return res;
    }
};