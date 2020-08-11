class MinStack {
public:
    stack<int> st; // regular stack
    stack<int> mono_st; // maintain a monotoically decreasing stack
    /** initialize your data structure here. */
    MinStack() {
        while(!st.empty()) st.pop();
        while(!mono_st.empty()) mono_st.pop();
    }
    
    void push(int x) {
        st.push(x);
        // Intuition:
        // Ex. stack = (top)| 3, 2, 4, 1, 5 |(bottom)
        // Once 1 exists, everything we add on it which is greater than 1 will not affect
        // the minimum among this stack!
        // Therefore, we can maintain a monotonic stack which only stores the monotonic
        // sequence among this stack: i.e.
        // (top)| 1, 5 |(bottom)
        if(mono_st.empty() or x <= mono_st.top()) mono_st.push(x);
    }
    
    void pop() {
        int tp = st.top();
        st.pop();
        if(mono_st.top() == tp) mono_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mono_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
