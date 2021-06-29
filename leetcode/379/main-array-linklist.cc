class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    // You can imagine this solution is a combination of
    // 1. a linked list
    // 2. a bool map which records whether this number is available
    // Basically, if next[i] == -1, that means this number is not available
    // else this means this number is available
    int n;
    int head;
    vector<int> next;
    
    PhoneDirectory(int maxNumbers) {
        n = maxNumbers;
        for(int i = 0; i < n; i++){
            next.push_back((i+1) % n);
        }
        head = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        // no more numbers are available
        if(next[head] == -1) return -1;
        int ret = head;
        head = next[head]; // move on to the next number
        next[ret] = -1; // implicitly remove this number
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return next[number] != -1;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(next[number] != -1) return; // already exist
        // Re-add this number as the head
        next[number] = head;
        head = number; // new head;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
