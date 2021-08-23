struct E{
    int val;
    int minimum;
};
class MinStack {
public:
    /** initialize your data structure here. */
    stack<E> stk;
    MinStack() {        
    }
    
    void push(int val) {
        if(stk.empty()) stk.push({val, val});
        else{
            stk.push({val, min(val, stk.top().minimum)});
        }
    }

    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().val;
    }
    
    int getMin() {
        return stk.top().minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
