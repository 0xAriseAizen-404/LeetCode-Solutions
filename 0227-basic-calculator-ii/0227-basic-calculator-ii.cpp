class Solution {
private:
    string myHelper(string str) {
        string operators = "+-%/^";
        string exp = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ')
                continue;
            else if (operators.find(str[i]) != string::npos) {
                if ((exp.empty() || exp.back() == '(') && str[i] == '-') {
                    exp += '0';
                }
                exp += str[i];
            } else {
                exp += str[i];
            }
        }
        return exp;
    }

    bool isOperator(char x) {
        return x == '+' || x == '-' || x == '*' || x == '%' || x == '/' ||
               x == '^';
    }

    int getPriority(char x) {
        switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
        }
    }

    vector<string> convertInfixToPostfix(string exp) {
        vector<string> res;
        stack<char> st;
        string num = "";

        for (char& x : exp) {
            if (isalnum(x)) {
                num += x;
            } else {
                if (!num.empty()) {
                    res.push_back(num);
                    num.clear();
                }

                if (x == '(') {
                    st.push(x);
                } else if (x == ')') {
                    while (!st.empty() && st.top() != '(') {
                        res.push_back(string(1, st.top()));
                        st.pop();
                    }
                    st.pop(); // Pop the '('
                } else if (isOperator(x)) {
                    while (!st.empty() &&
                           getPriority(st.top()) >= getPriority(x)) {
                        res.push_back(string(1, st.top()));
                        st.pop();
                    }
                    st.push(x);
                }
            }
        }

        if (!num.empty()) {
            res.push_back(num);
        }

        while (!st.empty()) {
            res.push_back(string(1, st.top()));
            st.pop();
        }

        return res;
    }

    int evaluatePostfix(vector<string> A) {
        stack<int> stk;

        for (auto& token : A) {
            if (token == "+" || token == "-" || token == "*" || token == "/" ||
                token == "%" || token == "^") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                if (token == "+")
                    stk.push(a + b);
                else if (token == "-")
                    stk.push(a - b);
                else if (token == "*")
                    stk.push(a * b);
                else if (token == "/")
                    stk.push(a / b);
                else if (token == "%")
                    stk.push(a % b);
                else if (token == "^")
                    stk.push(pow(a, b));
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }

public:
    int calculate(string s) {
        string expression = myHelper(s);
        // cout << expression << endl;
        vector<string> postFix = convertInfixToPostfix(expression);
        return evaluatePostfix(postFix);
    }
};
