class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        stack<char> bexp;
        for (auto x: expression) {
            if (x == '&' ||
                x == '|' ||
                x == '!') {
                    bexp.push(x);
                    continue;
            } else if (x == ',') continue;
            else if (x == ')') {
                // logic
                char help = bexp.top();
                bool val = st.top() == 'f' ? false : true; 
                while (!st.empty() && st.top() != '(' ) {
                    if (help == '&') val = val && (st.top() == 't' ? true : false);
                    else if (help == '|') val = val || (st.top() == 't' ? true : false);
                    else val = !val;
                    st.pop();
                }
                st.pop();
                bexp.pop();
                st.push(val == true ? 't' : 'f');
            } else st.push(x);
        }
        return st.top() == 't' ? true : false;
    }
};