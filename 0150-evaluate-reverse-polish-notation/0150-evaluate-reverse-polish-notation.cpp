class Solution {
private:
    bool isOperator (string &x) {
        return x == "+" || x == "-" || x == "/" || x == "%" || x == "*" || x == "^";
    }
    int myHelper (int op1, int op2, string &x) {
        int res = 0;
        switch (x[0]) {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '%':
                res = op1 % op2;
                break;
            case '^':
                res = op1 ^ op2;
                break;
        }
        return res;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1 = 0;
        int op2 = 0;
        for (string &x: tokens) {
            if (isOperator(x)) {
                op2 = st.top(); st.pop();
                op1 = st.top(); st.pop();
                // swap(op1, op2);
                // cout << op1 << " " << op2 << " " << x << endl;
                st.push(myHelper(op1, op2, x));
            } else {
                stringstream ss;
                int num = 0;
                ss << x; ss >> num;
                st.push(num);
                // st.push(stoi(x));
            }
        }
        return st.top();
    }
};