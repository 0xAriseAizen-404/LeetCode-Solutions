class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> newNums(nums);
        newNums.insert(newNums.end(), nums.begin(), nums.end());
        vector<int> res;
        stack<int> st;
        for (int i=newNums.size()-1; i>=0; --i) {
            while (!st.empty() && newNums[i] >= st.top()) st.pop();
            if (i < nums.size()) res.push_back(st.empty() ? -1 : st.top());
            st.push(newNums[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
