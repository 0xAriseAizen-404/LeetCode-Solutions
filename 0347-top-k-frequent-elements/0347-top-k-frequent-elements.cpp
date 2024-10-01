class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (const auto &x: nums) umap[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto &x: umap) {
            pq.push({x.second, x.first});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};