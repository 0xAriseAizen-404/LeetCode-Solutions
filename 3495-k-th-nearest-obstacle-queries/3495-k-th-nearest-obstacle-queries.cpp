class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int N = queries.size();
        vector<int> res(N, -1);
        // res.assign(N, -1);
        priority_queue<int> heap;
        for (int i=0; i<N; ++i) {
            int val = abs(queries[i][0]) + abs(queries[i][1]);
            heap.push(val);
            if (heap.size() > k) heap.pop();
            if (heap.size() == k) res[i] = heap.top();
        }
        return res;
    }
};