class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto &x: asteroids) {
            bool canPlace = true;
            while (!st.empty() && st.top() > 0 && x < 0) {
                if (st.top() < abs(x)) st.pop();
                else if (st.top() > abs(x)) {
                    canPlace = false;
                    break;
                } else {
                    st.pop();
                    canPlace = false;
                    break;
                }
            }
            if (canPlace) st.push(x);
        }
        vector<int> res(st.size(), 0);
        int ind = res.size() - 1;
        while (!st.empty()) {
            res[ind--] = st.top();
            st.pop();
        }
        return res;
    }
};