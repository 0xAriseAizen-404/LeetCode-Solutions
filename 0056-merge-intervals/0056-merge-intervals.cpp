class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] <= b[0];
        });
        vector<vector<int>> res;
        for (vector<int> coming: intervals) {
            if (!res.empty() && coming[0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1] , coming[1]);
            } else {
                res.push_back(coming);
            }
        }
        return res;
    }
};