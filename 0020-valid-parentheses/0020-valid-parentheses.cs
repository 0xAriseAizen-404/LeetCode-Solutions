public class Solution {
    public bool IsValid(string s) {
        Stack<char> st = new Stack<char>();
        foreach (char c in s) {
            if (c == '(' || c == '[' || c == '{') st.Push(c);
            else {
                if (st.Count == 0) return false;
                if ((c == ')' && st.Peek()!='(') ||
                    (c == ']' && st.Peek()!='[') ||
                    (c == '}' && st.Peek()!='{')) return false;
                st.Pop();
            }
        }
        return st.Count() == 0;
    }
}