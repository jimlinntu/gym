class MovingAverage {
public:
    /** Initialize your data structure here. */
    int size;
    int acc;
    queue<int> window;
    MovingAverage(int size) {
        this->size = size;
        acc = 0;
    }
    
    double next(int val) {
        window.push(val);
        acc += val;
        if(window.size() > size){
            // remove the leftmost
            acc -= window.front();
            window.pop();
        }
        return (double)acc / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
