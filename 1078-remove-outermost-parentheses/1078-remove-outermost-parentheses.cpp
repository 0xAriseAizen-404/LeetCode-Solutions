// class Solution {
// public:
//     string removeOuterParentheses(string S) {
//         string result;
//         int openCount = 0;

//         for (char c : S) {
//             if (c == '(') {
//                 if (openCount > 0) {
//                     result += c;
//                 }
//                 openCount++;
//             } else {
//                 openCount--;
//                 if (openCount > 0) {
//                     result += c;
//                 }
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
    string removeOuterParentheses(string paranthesis) {
        stack<char> st;
        string result = "";
        
        for (char x : paranthesis) {
            if (x == '(') {
                if (!st.empty()) {
                    result += x;
                }
                st.push(x);
            } else {
                st.pop();
                if (!st.empty()) {
                    result += x;
                }
            }
        }
        
        return result;
    }
};



// class Solution {
// public:
//     string removeOuterParentheses(string paranthesis) {
//         stack<int> st;
//         string result = "";
//         for (char x: paranthesis) {
//             if (x == '(') st.push(x);
//             else {
//                 if (st.size() == 0) result += x;
//                 if (st.size() == 1) {
//                     st.pop();
//                     continue;
//                 }
//                 else {
//                     while (st.size() != 1) {
//                         result += st.top();
//                         st.pop();
//                     }
//                     result += x;
//                 }
//             }
//         }
//         return result;
//     }
// };