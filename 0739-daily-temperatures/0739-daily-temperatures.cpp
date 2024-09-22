class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> mSt;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!mSt.empty() && temperatures[i] >= temperatures[mSt.top()])
                mSt.pop();
            if (!mSt.empty())
                ans[i] = mSt.top() - i;
            mSt.push(i);
        }
        return ans;
    }
};
