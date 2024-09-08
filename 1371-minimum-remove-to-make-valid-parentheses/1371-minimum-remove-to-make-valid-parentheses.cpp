class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<int> canAdd(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            char x = s[i];
            if (x == '(') st.push(i);
            else if (x == ')') {
                if (!st.empty()) {
                    canAdd[st.top()] = 1;
                    canAdd[i] = 1;
                    st.pop();
                }
            }
        }
        
        string res = "";
        for (int i=0, x=s[i]; i<n; ++i, x=s[i])  {
            // char x = s[i];
            if ((x == '(' || x == ')') && canAdd[i] == 0) continue;
            res += x;
        }
        return res;
    }
};
