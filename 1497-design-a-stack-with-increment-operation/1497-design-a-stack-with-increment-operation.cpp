class CustomStack {
    int *stack;
    int ind = -1;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stack = new int[maxSize]();
        ind = -1;
    }
    
    void push(int x) {
        if (ind + 1 < maxSize) {
            stack[++ind] = x;
        }
    }
    
    int pop() {
        if (ind == -1) return -1;
        return stack[ind--];
    }
    
    void increment(int k, int val) {
        int limit = min(k, ind + 1);
        for (int i = 0; i < limit; ++i) {
            stack[i] += val;
        }
    }

    ~CustomStack() {
        delete[] stack;
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */