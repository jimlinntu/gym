using Freq = int;
class FreqStack {
public:
    unordered_map<int, Freq> freq_map;
    // Observation 1: freq(num) <= n
    // Because freq(num) <= n, we can use a hashmap to store
    // all "frequency"
    // Observation 2: when the most frequent number x is popped out.
    //                The second frequent number must be x too!
    //                (Kind of linearity)
    // map[freq] = stack<int> (the purpose of this stack is to record which one comes later)
    unordered_map<Freq, stack<int>> map;
    int max_freq;
    
    FreqStack() {
        max_freq = 0;
    }

    void push(int val) {
        // (frequency of val)++
        int f = ++freq_map[val];
        max_freq = max(max_freq, f);
        // Insert this `val` at map[f]
        // map[ff <= f] will all have a val
        // Also, map[?] = stack<int> <-- must contain all unique values
        map[f].push(val);
    }
    
    int pop() {
        int num = map[max_freq].top();
        map[max_freq].pop();

        freq_map[num]--;

        // This frequency is out of elements, go to max_freq-1
        if(map[max_freq].size() == 0){
            map.erase(max_freq); // garbage collection
            max_freq--;
        }
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
