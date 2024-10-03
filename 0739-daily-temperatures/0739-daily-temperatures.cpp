class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> mSt;
        for (int i=n-1; i>=0; --i) {
            while (!mSt.empty() && temperatures[i] >= temperatures[mSt.top()])
                mSt.pop();
            res[i] = mSt.empty() ? 0 : (mSt.top() - i);
            mSt.push(i);
        }
        return res;
    }
};