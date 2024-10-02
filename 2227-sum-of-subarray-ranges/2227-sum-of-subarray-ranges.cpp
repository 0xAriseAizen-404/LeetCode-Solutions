class Solution {
public:
    long long sumSubArrayMaxs(vector<int> &nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        // prev-greater-element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next-greater-element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] > nums[st.top()]) 
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long MOD = 1e9 + 7;
        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            answer = (answer + ((long long)(i - left[i]) * (right[i] - i) * nums[i]));
        }
        return answer;
    }

    long long sumSubArrayMins(vector<int> &nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        // prev-smaller-element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next-smaller-element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] < nums[st.top()])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long MOD = 1e9 + 7;
        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            answer = (answer + ((long long)(i - left[i]) * (right[i] - i) * nums[i]));
        }
        return answer;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubArrayMaxs(nums) - sumSubArrayMins(nums);
    }
};
