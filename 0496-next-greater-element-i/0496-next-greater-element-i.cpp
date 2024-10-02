class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; st.push(nums2.back());
        unordered_map<int, int> umap;
        umap[nums2.back()] = -1;
        for (int i=nums2.size()-2; i>=0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();
            umap[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for (const auto &x: nums1) {
            if (umap.find(x) != umap.end()) {
                res.push_back(umap[x]);
            } else res.push_back(-1);
        }
        return res;
    }
};