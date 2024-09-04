class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string in;
        while (getline(ss, in, '/')) {
            if (in == "." || in == "") continue;
            if (in == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(in);
            }
        }
        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};
