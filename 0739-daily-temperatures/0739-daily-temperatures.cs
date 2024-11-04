public class Solution {
    public int[] DailyTemperatures(int[] temperatures) {
        int n = temperatures.Length;
        int[] res = new int[n];
        Stack<int> st = new Stack<int>();
        
        for (int i = n - 1; i >= 0; --i) {
            while (st.Count > 0 && temperatures[i] >= temperatures[st.Peek()]) {
                st.Pop();
            }
            res[i] = st.Count == 0 ? 0 : st.Peek() - i;
            st.Push(i);
        }
        
        return res;
    }
}
