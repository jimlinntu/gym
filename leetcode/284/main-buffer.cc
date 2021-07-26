/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    // if this is a generic type, we should add an additional bool variable
    // to check if there is one element in our buffer
    int buffer = -1;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(buffer != -1) return buffer;
        // Move forward (not visible to the user) and then store the result at the buffer
        return (buffer = Iterator::next());
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(buffer != -1){
            // return buffer first
            int ret = buffer;
            buffer = -1;
            return ret;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
        if(buffer != -1) return true;
	    return Iterator::hasNext();
	}
};
