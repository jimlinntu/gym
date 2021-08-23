class MovingAverage {
public:
    /** Initialize your data structure here. */
    int acc;
    // Queue: simulated by an array + a pointer
    vector<int> q;
    int r, q_size; // r is the ptr point to the next place to enqueue
    MovingAverage(int size) {
        acc = 0;
        q = vector<int>(size, 0);
        r = q_size = 0;
    }
    
    double next(int val) {
        // [0, 1, 2, 3]
        //  ^
        q_size = min((int)q.size(), ++q_size);
        acc -= q[r];
        q[r] = val;
        acc += q[r];
        r = (r+1) % q.size(); // move to the next position
        return (double)acc / q_size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
