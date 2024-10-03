class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<int> st;
        int n = heights.size();
        for (int i=0; i<=n; ++i) {
            int curr_height = (i == n) ? 0 : heights[i];
            while (!st.empty() && curr_height < heights[st.top()]) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }
};