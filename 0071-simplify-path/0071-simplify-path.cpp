class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string in;
        while (getline(ss, in, '/')) {
            if (!st.empty() && in == ".") continue;
            else if (st.empty() && in == ".") continue;
            else if (!st.empty() && in == "..") st.pop();
            else if (st.empty() && in == "..") continue;
            else if (in == "") continue;
            else st.push(in);
        }
        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return res=="" ? "/" : res;
    }
};