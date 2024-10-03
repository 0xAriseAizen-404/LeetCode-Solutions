class StockSpanner {
    int ind = 0;
    stack<pair<int, int>> st;
public:
    StockSpanner() { }

    int next(int price) {
        while (!st.empty() && price >= st.top().first) st.pop();
        int val = st.empty() ? ind + 1 : ind - st.top().second;
        st.push({price, ind++});
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */