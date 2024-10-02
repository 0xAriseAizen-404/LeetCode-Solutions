class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        stack<int> st;
        int max_area = INT_MIN;
        for (int i=0; i<N; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int NSE = i;
                int ele = st.top(); st.pop();
                int PSE = st.empty() ? -1 : st.top();
                max_area = max(max_area, (NSE - PSE - 1) * heights[ele]);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int NSE = N;
            int ele = st.top(); st.pop();
            int PSE = st.empty() ? -1 : st.top();
            max_area = max(max_area, (NSE - PSE - 1) * heights[ele]);
        }
        return max_area;
    }
};