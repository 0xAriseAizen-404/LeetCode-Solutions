class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int i = 0;
        int n = intervals.size();
        // Add intervals that come before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            merged.push_back(intervals[i]);
            i++;
        }
        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the merged new interval
        merged.push_back(newInterval);
        // Add remaining intervals
        while (i < n) {
            merged.push_back(intervals[i]);
            i++;
        }
        return merged;
    }
};