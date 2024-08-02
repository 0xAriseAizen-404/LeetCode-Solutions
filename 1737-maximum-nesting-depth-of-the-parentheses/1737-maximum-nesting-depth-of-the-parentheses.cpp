#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxDepth(std::string s) {
        std::stack<char> st;
        int maxNested = 0;
        for (char x: s) {
            if (x == '(') {
                st.push(x);
            } else if (x == ')') {
                st.pop();
            }
            maxNested = std::max(maxNested, static_cast<int>(st.size()));
        }
        return maxNested;
    }
};
