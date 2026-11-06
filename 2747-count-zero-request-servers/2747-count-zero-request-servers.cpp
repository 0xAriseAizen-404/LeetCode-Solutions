class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int K = queries.size();
        vector<int> ids(K);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });
        vector<int> ans(K);
        vector<int> cnt(n + 1, 0);
        int left = 0, right = 0, active = 0;
        for (int i : ids) {
            int q = queries[i];
            while (right < logs.size() && logs[right][1] <= q) {
                int id = logs[right][0];
                if (cnt[id] == 0) active++;
                cnt[id]++;
                right++;
            }
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left][0];
                cnt[id]--;
                if (cnt[id] == 0) active--;
                left++;
            }
            ans[i] = n - active;
        }
        return ans;
    }
};