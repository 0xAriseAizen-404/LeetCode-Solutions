class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i % n] >= st.top()) st.pop();
            if (i < n) res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i % n]);
        }
        
        return res;
    }
};


// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         vector<int> newNums(nums);
//         newNums.insert(newNums.end(), nums.begin(), nums.end());
//         vector<int> res;
//         stack<int> st;
//         for (int i=newNums.size()-1; i>=0; --i) {
//             while (!st.empty() && newNums[i] >= st.top()) st.pop();
//             if (i < nums.size()) res.push_back(st.empty() ? -1 : st.top());
//             st.push(newNums[i]);
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };
