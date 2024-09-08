class Solution {
public:
    int minAddToMakeValid(string s) {
        int help = 0;
        stack<char> st;
        for (char &x: s) {
            if (x == '(') st.push(x);
            else {
                if (st.empty()) help++;
                else st.pop();
            }
        }
        return st.size()+help;
    }
};