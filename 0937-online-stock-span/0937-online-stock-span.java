class Pair {
    public int first;
    public int second;
    Pair () {}
    Pair (int f, int s) {
        this.first = f;
        this.second = s;
    }
}
class StockSpanner {
    Stack<Pair> st;
    int ind;
    public StockSpanner() {
        this.st = new Stack<>();
        this.ind = 0;
    }
    
    public int next(int price) {
        while (!st.isEmpty() && price >= st.peek().first) st.pop();
        int val = st.isEmpty() ? ind + 1 : ind - st.peek().second;
        st.push(new Pair(price, ind++));
        return val;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */