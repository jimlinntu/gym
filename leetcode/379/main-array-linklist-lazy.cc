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
        assert(n > 0);
        // Only push one next pointer
        next.push_back(1 % n);
        head = 0;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(next[head] == -1) return -1;
        int ret = head; // the number we are gonna return
        head = next[head]; // move to the next number
        next[ret] = -1; // remove this number by nullify its pointer

        // The link list is at the end and we haven't meet our full size
        if(head == next.size() and next.size() < n){
            // lazy push back
            next.push_back((head+1)%n);
        }
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        // the number is beyond the current next pointers
        // so it must be available
        if(number >= next.size()) return true;
        return next[number] != -1;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        // beyound our current next pointers, ignore it
        if(number >= next.size()) return;
        // already exist
        if(next[number] != -1) return;
        next[number] = head; // point to the current head
        head = number; // new head
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
