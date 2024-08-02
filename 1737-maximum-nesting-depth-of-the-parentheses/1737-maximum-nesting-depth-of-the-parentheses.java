import java.util.Stack;

class Solution {
    public int maxDepth(String s) {
        Stack<Character> st = new Stack<>();
        int maxNested = 0;
        for (char x : s.toCharArray()) {
            if (x == '(') {
                st.push(x);
            } else if (x == ')') {
                if (!st.isEmpty()) {
                    st.pop();
                }
            }
            maxNested = Math.max(maxNested, st.size());
        }
        return maxNested;
    }
}
