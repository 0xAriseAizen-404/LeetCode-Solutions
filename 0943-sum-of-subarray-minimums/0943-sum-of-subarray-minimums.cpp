class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int length = arr.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);

        stack<int> st;

        for (int i = 0; i < length; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = length - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        long mod = 1e9 + 7;
        long long answer = 0;

        for (int i = 0; i < length; ++i) {
            answer = (answer + (long long)(i - left[i]) * (right[i] - i) % mod * arr[i] % mod) % mod;
        }

        return (int) answer;
    }
};
