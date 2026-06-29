class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        stack<int> pse;
        int max_area = INT_MIN;
        for (int nse=0; nse<=sz; ++nse) {
            while (!pse.empty() && (nse==sz || heights[pse.top()] >= heights[nse])) {
                int currH = heights[pse.top()]; pse.pop();
                int currW = nse - (pse.empty() ? -1 : pse.top()) - 1;
                max_area = max(max_area, currH * currW);
            }
            pse.push(nse);
        }
        return max_area;
    }
};