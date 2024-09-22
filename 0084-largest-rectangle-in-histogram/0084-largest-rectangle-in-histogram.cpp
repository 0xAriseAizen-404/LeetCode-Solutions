class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> mSt;
        int max_area = 0;
        int i = 0; 

        while (i < heights.size()) {
            int start = i;
            while (!mSt.empty() && mSt.top().second > heights[i]) {
                max_area = max(max_area, (i - mSt.top().first) * mSt.top().second);
                start = mSt.top().first;
                mSt.pop();
            }
            mSt.push(make_pair(start, heights[i]));
            ++i;
        }

        while (!mSt.empty()) {
            max_area = max(max_area, (i - mSt.top().first) * mSt.top().second);
            mSt.pop();
        }

        return max_area;
    }
};
