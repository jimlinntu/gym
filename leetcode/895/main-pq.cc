using Freq = int;
using Timestamp = int;
class FreqStack {
public:
    // max pq
    priority_queue<tuple<Freq, Timestamp, int>> pq;
    unordered_map<int, Freq> map;
    int timestamp;
    FreqStack() {
        timestamp = 0;
    }
    
    void push(int val) {
        int f = ++map[val];
        // Explanation:
        // Ex.        [1, 2, 3, 1, 1]
        // timestamp:  0  1  2  3  4 
        // freq        1  1  1  2  3
        
        // Frequency is placed as the first
        // because we want to pop the most frequent one
        // And the timestamp is also important because we want the most recent
        // one on the top
        // And val basically means nothing,
        // because of the timestamps are unique, we won't use it
        // to compare
        pq.push({f, timestamp++, val});
    }
    
    int pop() {
        int f, tidx, val;
        tie(f, tidx, val) = pq.top();
        pq.pop();
        map[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
