class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int unbalancedOnes = 0;
        for (char ch: s) {
            if (ch == '[') st.push(ch);
            else {
                if (!st.empty()) st.pop();
                else unbalancedOnes += 1;
            }
        }
        return (unbalancedOnes + 1) / 2;
    }
};