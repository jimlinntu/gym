class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1, q2;
    queue<int> *cur_q;
    queue<int> *other_q;
    MyStack() {
        cur_q = &q1, other_q = &q2;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        cur_q->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = top();
        cur_q->pop();
        swap(cur_q, other_q);
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        // cur_q will only have the top element
        while(cur_q->size() > 1){
            other_q->push(cur_q->front());
            cur_q->pop();
        }
        return cur_q->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return cur_q->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
