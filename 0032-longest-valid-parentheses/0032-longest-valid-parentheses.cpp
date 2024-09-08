class Solution {
public:
    int longestValidParentheses(string s) {
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
        
        // longest valid paranthesis - longest 1's substring
        int maxLenOfOnes = 0;
        int currLen = 0;
        for (int i=0; i<n; ++i) {
            if (canAdd[i] == 1) currLen++;
            else currLen = 0;
            maxLenOfOnes = max(maxLenOfOnes, currLen);
        }
        return maxLenOfOnes;
    }
};