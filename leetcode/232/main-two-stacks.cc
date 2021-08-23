class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> left, right;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        left.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        assert(!right.empty());
        right.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(!right.empty()){
            int x = right.top();
            return x;
        }else{
            // Pour things inside left to right
            assert(!left.empty());
            while(!left.empty()){
                right.push(left.top());
                left.pop();
            }
            return peek();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return left.empty() and right.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
